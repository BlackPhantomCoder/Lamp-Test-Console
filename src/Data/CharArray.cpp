#include "Data/CharArray.h"

CharArrayConstView::CharArrayConstView(const CharArray& arr):
	t_data(&arr),
	t_left(0),
	t_right(0)
{}

char CharArrayConstView::operator[](::byte i) const
{
	return (*t_data)[i + t_left];
}

void CharArrayConstView::remove_beg(::byte val)
{
	t_left += val;
}

void CharArrayConstView::remove_end(::byte val)
{
	t_right += val;
}

::byte CharArrayConstView::size() const
{
	return (*t_data).size() - t_left - t_right;
}