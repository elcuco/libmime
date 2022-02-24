/**-----------------------------------------------------------------------------------------------------------------
 * @file	header.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 * @note	Set an empty header with only default constructure
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/header.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const string &field_name)
{
	match_name = field_name;
}

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  field_name 
 *	@param[in]  _size - size of field_name 
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const char *field_name, string::size_type _size)
{
	match_name.assign(field_name, _size);
}

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  FName - class field_name obj reference
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const class field_name &FName)
{
	match_name = FName.get();
}

/**
 *	@brief	    Operator () overloading, set match condition for 'find_if()' 
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return	    true/false	
 **/
bool findIFname::operator()(const string &field_name)
{
	return util::string_cmp_ci(field_name, match_name);
}

/**
 *	@brief	    Operator () overloading, set match condition for 'find_if()' 
 *	@param[in]  _field - class field obj reference
 *	@param[out] None
 *	@return	    true/false	
 **/
bool findIFname::operator()(const class field &_field)
{
	return util::string_cmp_ci(_field.get_name(), match_name);
}

/**
 *	@brief	    Set header with field_line (push at the end of header)
 *	@param[in]  field_line
 *	@param[out] None
 *	@return		None
 **/
void header::set(const class field &field_line)
{
	headers.push_back(field_line);
	return;
}

header::header(const class field &field_line)
{
	this->set(field_line);
}

/**
 *	@brief	    Set header with string field_name and field_body instance 
 *	@param[in]  field_name
 *	@param[in]  pBody_t - field_body instance 
 *	@param[out] None
 *	@return		None
 **/
void header::set(const string &field_name, const class field_body *pBody_t)
{
	class field_name _name(field_name);

	class field _field(_name, pBody_t);

	this->set(_field);			return;
}

header::header(const string &field_name, const class field_body *pBody_t)
{
	this->set(field_name, pBody_t);
}

/**
 *	@brief	    Set header with string field_name and string instance body 
 *	@param[in]  field_name
 *	@param[in]  field_body - string instance 
 *	@param[out] None
 *	@return		None
 **/
void header::set(const string &field_name, const string &field_body)
{
	class field_name  _name(field_name);
	class string_body sbody(field_body);

	class field _field(_name, &sbody  );

	this->set(_field);           return;
}

header::header(const string &field_name, const string &field_body)
{
	this->set(field_name, field_body);
}

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _header 
 *	@param[out] None 
 *	@return	    Reference class header 
 **/
const class header &header::operator=(const class header &_header)
{
	this->headers = _header.headers;

	return _header;
}

/**
 *	@brief	    Get field by field name from header container
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    class field OR ""
 **/
class field &header::get_field(const string &field_name)
{
	deque<field>::iterator _inx;

	_inx = find_if(headers.begin(), headers.end(), findIFname(field_name));

	return (_inx != headers.end())?(*_inx):(field::null_field);
}

/**
 *	@brief	    Get field by position index from header container
 *	@param[in]  position 
 *	@param[out] None 
 *	@return	    field at position 
 **/
class field &header::get_field(size_t pos)
{ 
	return (pos >= this->headers.size())?(field::null_field):this->headers.at(pos);
}

/**
 *	@brief	    Get field by field name from header container
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    class field OR ""
 **/
const class field &header::get_field(const string &field_name) const noexcept
{
	deque<field>::const_iterator _inx;

	_inx = find_if(headers.begin(), headers.end(), findIFname(field_name));

	return (_inx != headers.end())?(*_inx):(field::null_field);
}

/**
 *	@brief	    Get header(s)
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    header(s) 
 **/
const string header::get(void) const noexcept
{
	string headers_str;

	deque<field>::const_iterator _big = headers.begin(), _end = headers.end();

	while (_big != _end)
	{
		headers_str += _big->get();
		_big++;
	}

	return headers_str + "\r\n";
}

/**
 *	@brief	    Juge if header is empty or not 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    true/flase 
 **/
bool header::is_empty(void) { return headers.empty(); }

/**
 *	@brief	    Juge the header name exists whether or not
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    true/flase 
 **/
bool header::exist_field(const string &field_name)
{
	return (!get_field(field_name).is_empty());
}

/**
 *	@brief	    Clear header 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    None 
 **/
void header::clear(void) 
{ 
	deque<field>::iterator _big = headers.begin(), _end = headers.end();

	while (_big != _end){
		_big->clear(); _big++; /**< Clear field_body */
	}	

	headers.clear();  return;
}

/**
 *	@brief	    Delete a field of headers
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return	    None 
 **/
void header::remove(const string &field_name)
{
	deque<field>::iterator _inx;

	_inx = find_if(headers.begin(), headers.end(), findIFname(field_name));

	if (_inx != headers.end())
	{
		this->headers.erase(_inx);	
	}

	return;
}

