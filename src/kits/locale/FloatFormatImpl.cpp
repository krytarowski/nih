#include <os/locale/FloatFormatImpl.h>
#include <os/locale/FloatFormatParameters.h>

// constructor
BFloatFormatImpl::BFloatFormatImpl()
	: BNumberFormatImpl()
{
}

// destructor
BFloatFormatImpl::~BFloatFormatImpl()
{
}

// DefaultNumberFormatParameters
BNumberFormatParameters *
BFloatFormatImpl::DefaultNumberFormatParameters()
{
	return DefaultFloatFormatParameters();
}

// DefaultNumberFormatParameters
const BNumberFormatParameters *
BFloatFormatImpl::DefaultNumberFormatParameters() const
{
	return DefaultFloatFormatParameters();
}

