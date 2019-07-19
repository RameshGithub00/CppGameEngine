#pragma once
#include <core/ceTypes.h>
namespace math
{
	
	class Vec2
	{
		
		f32 x, y;

	public:
		Vec2(f32 _x = 0, f32 _y = 0) :x(_x), y(_y) {}

	
		inline Vec2 operator+(Vec2& other)
		{
			Vec2 ret;
			ret.x = x + other.x;
			ret.y = y + other.y;
			return ret;
		}
	};

	class Vec3
	{
		f32 x;
		f32 y;
		f32 z;

	public:
		Vec3(f32 _x = 0, f32 _y = 0, f32 _z = 0):x(_x),y(_y),z(_z) {}

	
		inline Vec3 operator+(Vec3& other)
		{
			Vec3 ret;
			ret.x = x + other.x;
			ret.y = y + other.y;
			ret.z = z + other.z;
			return ret;
		}
	};
}