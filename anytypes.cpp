#include "anytypes.h"

namespace ISXTypesSpace
{

AnyTypes::AnyTypes(const AnyTypes& copy)
{
	data_type = copy.data_type;
	data = copy.data;
}

AnyTypes::AnyTypes(AnyTypes&& move)
{
	this->data_type = std::move(move.data_type);
	this->data = std::move(move.data);
}

AnyTypes::AnyTypes(bool b) : data_type(Types::BOOL)
{
	data.b = b;
}

AnyTypes::AnyTypes(char c) : data_type(Types::CHAR)
{
	data.c = c;
}

AnyTypes::AnyTypes(unsigned char uc) : data_type(Types::U_CHAR)
{
	data.uc = uc;
}

AnyTypes::AnyTypes(wchar_t wc_t) : data_type(Types::WCHAR_T)
{
	data.wc_t = wc_t;
}

AnyTypes::AnyTypes(short s) : data_type(Types::SHORT)
{
	data.s = s;
}

AnyTypes::AnyTypes(unsigned short us) : data_type(Types::U_SHORT)
{
	data.us = us;
}

AnyTypes::AnyTypes(int i) : data_type(Types::INT)
{
	data.i = i;
}

AnyTypes::AnyTypes(unsigned int ui) : data_type(Types::U_INT)
{
	data.ui = ui;
}

AnyTypes::AnyTypes(long int li) : data_type(Types::L_INT)
{
	data.li = li;
}

AnyTypes::AnyTypes(unsigned long int uli) : data_type(Types::U_L_INT)
{
	data.uli = uli;
}

AnyTypes::AnyTypes(long long int lli) : data_type(Types::L_L_INT)
{
	data.lli = lli;
}

AnyTypes::AnyTypes(unsigned long long int ulli) : data_type(Types::U_L_L_INT)
{
	data.ulli = ulli;
}

AnyTypes::AnyTypes(float f) : data_type(Types::FLOAT)
{
	data.f = f;
}

AnyTypes::AnyTypes(double d) : data_type(Types::DOUBLE)
{
	data.d = d;
}

AnyTypes::AnyTypes(long double ld) : data_type(Types::L_DOUBLE)
{
	data.ld = ld;
}

AnyTypes::AnyTypes()
{
	std::cout << "dector" << std::endl;
}

AnyTypes& AnyTypes::operator=(const AnyTypes& right)
{
	data_type = right.data_type;
	data = right.data;
	return *this;
}

AnyTypes& AnyTypes::operator=(AnyTypes&& right)
{
	data_type = std::move(right.data_type);
	data = std::move(right.data);
	return *this;
}

const char* AnyTypes::get_type_name() const
{
	switch (data_type)
	{
	case Types::BOOL:
		return "Bool";
	case Types::CHAR:
		return "Char";
	case Types::U_CHAR:
		return "Unsigned Char";
	case Types::WCHAR_T:
		return "Wchar_t";
	case Types::SHORT:
		return "Short";
	case Types::U_SHORT:
		return "Unsigned Short";
	case Types::INT:
		return "int";
	case Types::U_INT:
		return "Unsigned Int";
	case Types::L_INT:
		return "Long Int";
	case Types::U_L_INT:
		return "Unsigned Long Int";
	case Types::L_L_INT:
		return "Long Long Int";
	case Types::U_L_L_INT:
		return "Unsigned Long Long Int";
	case Types::FLOAT:
		return "Float";
	case Types::DOUBLE:
		return "Double";
	case Types::L_DOUBLE:
		return "Long Double";
	case Types::NONE:
		return "Invalid type";
	}
}

bool AnyTypes::get_bool() const
{
    if(data_type == Types::BOOL)
        return data.b;
    else 
        throw std::bad_cast();
}

char AnyTypes::get_char() const
{
    if(data_type == Types::CHAR)
        return data.c;
    else 
        throw std::bad_cast();
}

unsigned char AnyTypes::get_unsigned_char() const
{
    if(data_type == Types::U_CHAR)
        return data.uc;
    else 
        throw std::bad_cast();
}

wchar_t AnyTypes::get_wchar_t() const
{
    if(data_type == Types::WCHAR_T)
        return data.wc_t;
    else 
        throw std::bad_cast();
}

short AnyTypes::get_short() const
{
    if(data_type == Types::SHORT)
        return data.s;
    else 
        throw std::bad_cast();
}

unsigned short AnyTypes::get_unsigned_short() const
{
    if(data_type == Types::U_SHORT)
        return data.us;
    else
        throw std::bad_cast();
}

int AnyTypes::get_int() const
{
    if(data_type == Types::INT)
        return data.i;
    else 
        throw std::bad_cast();
}

unsigned int AnyTypes::get_unsigned_int() const
{
    if(data_type == Types::U_INT)
        return data.ui;
    else 
        throw std::bad_cast();
}

long int AnyTypes::get_long_int() const
{
    if(data_type == Types::L_INT)
        return data.li;
    else 
        throw std::bad_cast();
}

unsigned long int AnyTypes::get_unsigned_long_int() const
{
    if(data_type == Types::U_L_INT)
        return data.uli;
    else 
        throw std::bad_cast();
}

long long int AnyTypes::get_long_long_int() const
{
    if(data_type == Types::L_L_INT)
        return data.lli;
    else 
        throw std::bad_cast();
}

unsigned long long int AnyTypes::get_unsigned_long_long_int() const
{
    if(data_type == Types::U_L_L_INT)
        return data.ulli;
    else 
        throw std::bad_cast();
}

float AnyTypes::get_float() const
{
    if(data_type == Types::FLOAT)
        return data.f;
    else 
        throw std::bad_cast();
}

double AnyTypes::get_double() const
{
    if(data_type == Types::DOUBLE)
        return data.d;
    else
        throw std::bad_cast();
}

long double AnyTypes::get_long_double() const
{
    if(data_type == Types::L_DOUBLE)
        return data.ld;
    else
        throw std::bad_cast();
}

std::ostream& operator<<(std::ostream& out, const AnyTypes& target)
{
	out << target.get_type_name() << "\t";

		switch (target.get_type())
	{
	case Types::BOOL:
		return out << target.data.b;
	case Types::CHAR:
		return out << target.data.c;
	case Types::U_CHAR:
		return out << target.data.uc;
	case Types::WCHAR_T:
		return out << target.data.wc_t;
	case Types::SHORT:
		return out << target.data.s;
	case Types::U_SHORT:
		return out << target.data.us;
	case Types::INT:
		return out << target.data.i;
	case Types::U_INT:
		return out << target.data.ui;
	case Types::L_INT:
		return out << target.data.li;
	case Types::U_L_INT:
		return out << target.data.uli;
	case Types::L_L_INT:
		return out << target.data.lli;
	case Types::U_L_L_INT:
		return out << target.data.ulli;
	case Types::FLOAT:
		return out << target.data.f;
	case Types::DOUBLE:
		return out << target.data.d;
	case Types::L_DOUBLE:
		return out << target.data.ld;
	case Types::NONE:
		return out << "invalid type";
	}
}

}