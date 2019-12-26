#pragma once
#include "core/ceString.h"
namespace ce
{
	class Vec3
	{
		f32 x;
		f32 y;
		f32 z;

	public:

		Vec3(f32 x, f32 y, f32 z) :x(x), y(y), z(z) 
		{}

		static Vec3 GetZero() { return Vec3(.0f, .0f, .0f); }

		inline Vec3 operator+(Vec3& other)
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}

		inline Vec3 operator-(Vec3& other)
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}

		inline void Normalize()
		{

		}

		inline Vec3 GetNormalized()
		{
			Vec3::GetZero();
		}

		inline static f32 GetCosine(Vec3& v1, Vec3& v2)
		{

			return 0.0f;
		}

		inline static f32 GetSine(Vec3& v1, Vec3& v2)
		{
			return 0.0f;
		}

		inline static f32 Dot(Vec3& v1, Vec3& v2)
		{
			return 0.0f;
		}

		inline String getDescription()
		{
			String ss;
			return ss + x + " " + y + " " + z;
		}
	};

}