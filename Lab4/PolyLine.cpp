#include <cstring>
#include <cmath>
#include <climits>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPointCnt(0)
	{
		for (int i = 0; i < 10; i++)
		{
			mPointArr[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mPointCnt(other.mPointCnt)
	{
		for (int i = 0; i < 10; i++)
		{
			if (other.mPointArr[i] != nullptr)
			{
				const Point* tmp = other.mPointArr[i];
				mPointArr[i] = new Point(tmp->GetX(), tmp->GetY());
				continue;
			}
			mPointArr[i] = nullptr;
		}

	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		if (rhs.mPointArr == mPointArr)
		{
			return *this;
		}
		for (int i = 0; i < mPointCnt; i++)
		{
			delete mPointArr[i];
			mPointArr[i] = nullptr;
		}
		for (int i = 0; i < rhs.mPointCnt; i++)
		{
			mPointArr[i] = new Point(rhs.mPointArr[i]->GetX(), rhs.mPointArr[i]->GetY());
		}
		mPointCnt = rhs.mPointCnt;
		return *this;
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < mPointCnt; i++)
		{
			delete mPointArr[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCnt >= 10)
		{
			return false;
		}

		mPointArr[mPointCnt++] = new Point(x, y);
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mPointCnt >= 10)
		{
			return false;
		}

		mPointArr[mPointCnt++] = point;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= 10)
		{
			return false;
		}
		if (mPointArr[i] != nullptr)
		{
			delete mPointArr[i];
			mPointArr[i] = nullptr;
			for (int j = i; j < 9; j++)
			{
				const Point* tmp = mPointArr[j];
				mPointArr[j] = mPointArr[j + 1];
				mPointArr[j + 1] = tmp;
			}
			mPointCnt--;
			return true;
		}

		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mPointCnt == 0)
		{
			return false;
		}

		float minX = std::numeric_limits<float>::max();
		float minY = std::numeric_limits<float>::max();
		float maxX = std::numeric_limits<float>::lowest();
		float maxY = std::numeric_limits<float>::lowest();
		for (int i = 0; i < mPointCnt; i++)
		{
			minX = std::min(minX, mPointArr[i]->GetX());
			minY = std::min(minY, mPointArr[i]->GetY());
			maxX = std::max(maxX, mPointArr[i]->GetX());
			maxY = std::max(maxY, mPointArr[i]->GetY());
		}
		outMin->SetX(minX);
		outMin->SetY(minY);
		outMax->SetX(maxX);
		outMax->SetY(maxY);
		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= 10)
		{
			return nullptr;
		}
		return mPointArr[i];
	}
}