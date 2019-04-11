#include "pch.h"
#include "TV_Test/check_state.h"

void ExpectOperationSuccess(CTVSet& tv, function<bool(CTVSet&tv)> const& op, boost::optional<int> const& expectedChannel)
{

	CHECK(op(tv)); // ���������, ��� �������� ���������� �������
	// ���������� ������������ � ����� � ���������� ����������
	CHECK(tv.IsTurnedOn() == expectedChannel.has_value());
	CHECK(tv.GetChannel() == expectedChannel.value_or(0));
}

void ExpectOperationFailure(const CTVSet& tv, const function<bool(CTVSet&tv)>& op)
{
	CTVSet tvCopy(tv); // ����� ����������, ��� ������� ����� ����������� ��������
	CHECK(!op(tvCopy)); // ���������, ��� �������� (��� ������) ���������� ���������
	// ���������� ������������ � ����� � �������� ����������
	CHECK(tvCopy.IsTurnedOn() == tv.IsTurnedOn());
	CHECK(tvCopy.GetChannel() == tv.GetChannel());
}
