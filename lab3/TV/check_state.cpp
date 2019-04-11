#include "pch.h"
#include "TV_Test/check_state.h"

void ExpectOperationSuccess(CTVSet& tv, function<bool(CTVSet&tv)> const& op, boost::optional<int> const& expectedChannel)
{

	CHECK(op(tv)); // убедились, что операция завершится успешно
	// сравниваем включенность и канал с ожидаемыми значениями
	CHECK(tv.IsTurnedOn() == expectedChannel.has_value());
	CHECK(tv.GetChannel() == expectedChannel.value_or(0));
}

void ExpectOperationFailure(const CTVSet& tv, const function<bool(CTVSet&tv)>& op)
{
	CTVSet tvCopy(tv); // копия телевизора, над которой будет выполняться операция
	CHECK(!op(tvCopy)); // убедились, что операция (над копией) завершится неуспешно
	// сравниваем включенность и канал с прежними значениями
	CHECK(tvCopy.IsTurnedOn() == tv.IsTurnedOn());
	CHECK(tvCopy.GetChannel() == tv.GetChannel());
}
