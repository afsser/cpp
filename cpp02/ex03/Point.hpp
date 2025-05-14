#ifndef POINT_HPP
# define POINT_HPP

# include <cmath>

class Point
{
	private:
		const float _x;
		const float _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point();

		bool bsp(const Point &a, const Point &b, const Point &c) const;
};

#endif