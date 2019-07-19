#pragma once

template<typename T>
void ecSwap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<>
void ecSwap(u32& a, u32& b)
{
	a = a ^ b;
	b = a ^ b;// b = a
	a = a ^ b;//a = b
}
