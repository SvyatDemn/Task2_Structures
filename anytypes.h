#pragma once
#include <iostream>

namespace ISXTypesSpace
{

enum class Types
{
	NONE = -1,

	BOOL = 0, 

	CHAR = 1, 
	U_CHAR = 2,
	WCHAR_T = 3, 
	
	SHORT = 4, 
	U_SHORT = 5, 
	INT = 6,
	U_INT = 7,
	L_INT = 8,
	U_L_INT = 9,
	L_L_INT = 10,
	U_L_L_INT = 11,

	FLOAT = 12,
	DOUBLE = 13, 
	L_DOUBLE = 14,
};

union AnyValues
{
	bool b;

	char c;
	unsigned char uc;
	wchar_t wc_t;

	short s;
	unsigned short us;
	int i;
	unsigned int ui;
	long int li;
	unsigned long int uli;
	long long int lli;
	unsigned long long int ulli;

	float f;
	double d;
	long double ld;
};

class AnyTypes
{
public:
	//Constructures
	AnyTypes();
	AnyTypes(const AnyTypes& copy);
	AnyTypes(AnyTypes&& move);
	AnyTypes(bool b);
	AnyTypes(char c);
	AnyTypes(unsigned char uc);
	AnyTypes(wchar_t wc_t);
	AnyTypes(short s);
	AnyTypes(unsigned short	us);
	AnyTypes(int i);
	AnyTypes(unsigned int ui);
	AnyTypes(long int il);
	AnyTypes(unsigned long int uli);
	AnyTypes(long long int lli);
	AnyTypes(unsigned long long int	ulli);
	AnyTypes(float f);
	AnyTypes(double d);
	AnyTypes(long double ld);
	~AnyTypes();

	AnyTypes& operator=(const AnyTypes& right);
	AnyTypes& operator=(AnyTypes&& right);

	friend std::ostream& operator<<(std::ostream& out, const AnyTypes& target);
	//Geters
	const char* get_type_name() const;
	bool get_bool() const;
	char get_char() const;
	unsigned char get_unsigned_char() const;
	wchar_t	get_wchar_t() const;
	short  get_short() const;
	unsigned short  get_unsigned_short() const;
	int get_int() const;
	unsigned int get_unsigned_int() const;
	long int get_long_int() const;
	unsigned long int get_unsigned_long_int() const;
	long long int get_long_long_int() const;
	unsigned long long int get_unsigned_long_long_int() const;
	float get_float() const;
	double get_double() const;
	long double get_long_double() const;

private:
	Types data_type;
	AnyValues data;
	Types get_type() const { return data_type; }

};

}