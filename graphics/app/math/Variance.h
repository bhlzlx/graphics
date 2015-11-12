#ifndef __MATH_VARIANCE_H__
#define __MATH_VARIANCE_H__

namespace Math
{

	class Variance
	{
	private:
		float m_fCount;
		float m_fD1;
		float m_fD2;
	public:
		Variance();
		~Variance();
		void Reset();
		void Input( float _fValue);
		float End();
	};
};

#endif // __MATH_VARIANCE_H__
