/**-----------------------------------------------------------------------------------------------------------------
 * @file	field_name.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/field_name.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set field name 
 *	@param[in]  name - field name 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
void field_name::set(const string &name)
{
	string::const_iterator _index = name.begin(), _end = name.end();

	while (_index != _end)
	{
		if ((*_index < FIELD_NAME_ASCII_SCOPE_MIN) || (*_index > FIELD_NAME_ASCII_SCOPE_MAX) 
				|| (*_index == FIELD_NAME_ASCII_EXCLUDECH))
		{
			throw("Exception : 'field_name.cpp' - Character out of range!");
		}

		_index++;
	}

	this->name = name;

	return;
}

field_name::field_name(const string &name) { this->set(name); }

/**
 *	@brief	    Set field name 
 *	@param[in]  name  - field name 
 *	@param[in]  _size - size of field name 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
void field_name::set(const char *name, size_t _size)
{
	const char *_index = name;

	this->name.clear();

	while ((*_index != '\0') && (_size-- != 0))
	{
		if ((*_index < FIELD_NAME_ASCII_SCOPE_MIN) || (*_index > FIELD_NAME_ASCII_SCOPE_MAX)
				|| (*_index == FIELD_NAME_ASCII_EXCLUDECH))
		{
			this->name.clear();

			throw("Exception : 'field_name.cpp' - Character out of range!");
		}

		this->name.append(1, *_index);

		_index++;
	}

	if (*_index != '\0') {this->name.append(1, '\0');}

	return;
}

field_name::field_name(const char *name, size_t _size) { this->set(name, _size); }

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  rname_t - class field_name reference 
 *	@param[out] None
 *	@return	    class field_name reference	
 **/
const class field_name &field_name::operator=(const class field_name &rname_t)
{
	this->name = rname_t.name;

	return rname_t;
}

/**
 *	@brief	    Operator '==' overloading 
 *	@param[in]  rname_t - class field_name reference 
 *	@param[out] None
 *	@return		true/false	
 **/
bool field_name::operator==(const class field_name &rname_t)
{
	return (this->name == rname_t.name);
}

/**
 *	@brief	    Get field name 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
const string &field_name::get(void) const noexcept 
{
	return name;
}

