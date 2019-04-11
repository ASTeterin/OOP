#pragma once
#include "pch.h"

void ExpectOperationSuccess(CTVSet& tv, function<bool(CTVSet&tv)> const& op, boost::optional<int> const& expectedChannel);
void ExpectOperationFailure(const CTVSet& tv, const function<bool(CTVSet&tv)>& op);