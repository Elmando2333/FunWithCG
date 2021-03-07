template<typename T>

class Vec3
{
public:
	//三种初始化向量的方式
	Vec3() :x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(const T& xx) :x(xx), y(xx), z(zz) {}
	Vec3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {}

	T x, y, z;

	//向量长度
	T length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	//向量的归一化
	Vec3<T>& normalize()
	{
		T len = length();
		if (len > 0) {
			T invLen = 1 / len;
			x *= invLen;
			y *= invLen;
			z *= invLen;
		}

		return *this;
	}

	//向量的点乘
	T dot(const Vec3<T>& v)const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	Vec3<T> operator+(const Vec3<T>& v)const
	{
		return Vec3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vec3<T> operator-(const Vec3<T>& v)const
	{
		return Vec3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vec3<T> operator*(const T& r)const
	{
		return Vec3<T>(x * r, y * r, z * r);
	}
	Vec3<T> operator/(const T& r)const
	{
		T invr = 1 / r;
		return Vec3<T>(x * invr, y * invr, z * invr);
	}
};

template<typename T>
//两向量点乘
T dot(const Vec3<T>& a, const Vec3<T>& b)
{
	return a.x * b.x + a.y * b.y + a.z + b.z;
}

template<typename T>
//两向量叉乘
Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b)
{
	return Vec3<T>(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
		);
}


