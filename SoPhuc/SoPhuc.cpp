#include "SoPhuc.h"

SoPhuc SoPhuc:: operator+(const SoPhuc& other) const
{
	SoPhuc sum;
	sum.Thuc = Thuc + other.Thuc;
	sum.Ao = Ao + other.Ao;
	return sum;
}
SoPhuc SoPhuc:: operator-(const SoPhuc& other) const
{
	SoPhuc minus;
	minus.Thuc = Thuc - other.Thuc;
	minus.Ao = Ao - other.Ao;
	return minus;
}
SoPhuc SoPhuc:: operator*(const SoPhuc& other) const
{
	SoPhuc Tich;
	Tich.Thuc = Thuc * other.Thuc - Ao * other.Ao;
	Tich.Ao = Ao * other.Thuc + Thuc * other.Ao;

	return Tich;
}
SoPhuc SoPhuc:: operator/(const SoPhuc& other) const
{
	SoPhuc Thuong;
	Thuong.Thuc = (Thuc * other.Thuc + Ao * other.Ao) / (other.Thuc * other.Thuc + other.Ao * other.Ao);
	Thuong.Ao = (Ao * other.Thuc - Thuc * other.Ao) / (other.Thuc * other.Thuc + other.Ao * other.Ao);

	return Thuong;
}
bool SoPhuc:: operator == (const SoPhuc& other) const
{
	return (Thuc == other.Thuc) && (Ao == other.Ao);
}
bool SoPhuc:: operator != (const SoPhuc& other) const
{
	return (*this == other);
}

istream& operator >> (istream& in, SoPhuc& This)
{
	cout << "Nhap phan thuc: ";
	in >> This.Thuc;
	cout << "Nhap phan ao: ";
	in >> This.Ao;
	return in;
}
ostream& operator << (ostream& out, const SoPhuc& This)
{
	if (This.Thuc == 0)
	{
		if (This.Ao == 0)
			out << 0;
		else
			out << This.Ao<<'i';
	}
	else
	{
		out << This.Thuc;
		if (This.Ao > 0)
			out << '+' << This.Ao << 'i';
		else
		{
			if (This.Ao != 0)
				out << This.Ao << 'i';
		}
	}

	return out;
}