#include "Variance.h"
#include <math.h>


namespace Math
{

	Variance::Variance()
	{
		Reset();
	}

	Variance::~Variance()
	{
	}

	float Variance::End()
	{
		return (m_fD1 / m_fCount) - pow(m_fD2/m_fCount, 2);
	}

	void Variance::Input(float _fValue)
	{
		++this->m_fCount;
		this->m_fD1 += pow(_fValue, 2);
		this->m_fD2 += _fValue;
	}

	void Variance::Reset()
	{
		this->m_fCount = this->m_fD1 = this->m_fD2 = 0;
	}
}

