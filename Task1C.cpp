#include <iostream>
#include <string>
#define print cout<<
using namespace std;

class shapes
{
protected:
	double length, width;

public:
	shapes() : length(0), width(0) {}
	~shapes() {}
	
	virtual void setter();
	virtual double area() = 0;
	virtual double getLength();
	virtual double getWidth();

};


class two_d_shapes : public shapes
{
public:
	two_d_shapes() {}
	~two_d_shapes() {}

	virtual double area() = 0;
};


class circle : public two_d_shapes
{
protected:
	double radius;
	string color;

public:
	circle() : radius(0), color(""), two_d_shapes() {}
	~circle() {}

	void		setter();
	double		getLength();
	double		getWidth();
	double		getRadius();
	string		getColor();
	double		area();
};


class square : public two_d_shapes
{
protected:
	double side;
	string color;

public:
	square() : side(0), color(""), two_d_shapes() {}
	~square() {}

	void		setter();
	double		getLength();
	double		getWidth();
	double		getSide();
	string		getColor();
	double		area();
};


class three_d_shapes : public shapes
{
public:
	three_d_shapes () : shapes() {}
	~three_d_shapes()	{}
	virtual double area() = 0;
	virtual double volume() = 0;
};

class Cube : public three_d_shapes
{
protected:
	double length, width, height;

public:
	Cube() : length(0), width(0), height(0), three_d_shapes() {}
	~Cube() {}
	void		setter();
	double		getLength();
	double		getWidth();
	double		getHeight();
	double		area();
	double		volume();
};

class Pyramid : public three_d_shapes
{
protected:
	double base, height;

public:
	Pyramid() : base(0), height(0), three_d_shapes() {}
	~Pyramid() {}


	void		setter();
	double		getBase();
	double		getHeight();
	double		area();
	double		volume();
		
};

//shapes
void shapes::setter() 
{
	print"\nEnter length\n>>\t";
	cin >> length;
	print"\nEnter width\n>>\t";
	cin >> width;
}
double shapes::getLength()			{ return length; }
double shapes::getWidth()			{ return width; }

//circle 
double		circle::getLength()		{ return length; }
double		circle::getWidth()		{ return width; }
double		circle::getRadius()		{ return radius; }
string		circle::getColor()		{ return color; }
double		circle::area()			{ return (3.14 * (radius * radius)); }
void		circle::setter()
{
	print"\nEnter radius\n>>\t";
	cin >> radius;
	print"\nEnter color\n>>\t";
	cin >> color;
	getchar();		//to eliminate null character in buffer
}


//square
double		square::getLength()		{ return length; }
double		square::getWidth()		{ return width; }
double		square::getSide()		{ return side; }
string		square::getColor()		{ return color; }
double		square::area()			{ return side*side; }
void		square::setter()
{
	print"\nEnter side\n>>\t";
	cin >> side;
	print"\nEnter color\n>>\t";
	cin >> color;
	//getchar();		//to eliminate null character in buffer
}


//cube
double		Cube::getLength()		{ return length; }
double		Cube::getWidth()		{ return width; }
double		Cube::getHeight()		{ return height; }
double		Cube::area()			{ return (2 * ((length * width) + (width * height) + (length * height))); }
double		Cube::volume()			{ return length * width * height; }
void		Cube::setter()
{
	print"\nEnter length\n>>\t";
	cin >> length;
	print"\nEnter width\n>>\t";
	cin >> width;
	print"\nEnter height\n>>\t";
	cin >> height;
}


//pyramid
double		Pyramid::getBase()		{ return base; }
double		Pyramid::getHeight()	{ return height; }
double		Pyramid::area()			{ return ((base * base) + (2 * base * height)); }
double		Pyramid::volume()		{ return ((0.333) * (area()) * height); }
void		Pyramid::setter()
{
	print"\nEnter base\n>>\t";
	cin >> base;
	print"\nEnter height\n>>\t";
	cin >> height;
}








int main()
{
	shapes* s[2];
	two_d_shapes* twoD;
	three_d_shapes* threeD;
	circle Circle;
	square Square;
	Cube cube;
	Pyramid pyramid;

	s[0] = &Circle;		//points to circle object
	s[1] = &cube;		//points to cube object

	twoD = &Square;		//points to square object
	threeD = &pyramid;	//points to pyramid object

	print"\n\n\n==================(Circle)==================\n";
	s[0]->setter();
	print "\nradius\t" << Circle.getRadius();
	print "\ncolor\t" << Circle.getColor();
	print "\nArea\t" << s[0]->area();

	print "\n\n\n==================(Square)==================\n";
	twoD->setter();
	print "\nside\t" << Square.getSide();
	print "\ncolor\t" << Square.getColor();
	print "\nArea\t" << twoD->area();


	print "\n\n\n==================(Cube)==================\n";
	s[1]->setter();
	print "\nlength\t"<<s[1]->getLength();
	print "\nWidth\t" << s[1]->getWidth();
	print "\nHeight\t" << cube.getHeight();
	print "\nArea\t" << s[1]->area();
	print "\nVolume\t" << cube.volume();

	print "\n\n\n==================(Pyramid)==================\n";
	threeD->setter();
	print "\nBase\t" << pyramid.getBase();
	print "\nHeight\t" << pyramid.getHeight();
	print "\nArea\t" << threeD->area();
	print "\nVolume\t" << threeD->volume();


	return 0;
}