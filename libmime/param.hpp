/**-----------------------------------------------------------------------------------------------------------------
 * @file	param.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_PARAM_HPP__
#define __LIBMIME_PARAM_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												PARAM INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>
#include <libmime/field_body.hpp>
#include <libmime/util.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												PARAM SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												PARAM DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief param class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class param{
	public:
		param(){}; /**< Empty structure */
		param(const string &param												);
		param(const char *param, string::size_type _size						);
		param(const string &attr, const string &value							);

		void set(const string &param											);
		void set(const char *param, string::size_type _size						);
		void set(const string &attr, const string &value						);

		const string &get(void) const noexcept									 ;

		const string get_attr (void) const noexcept								 ;
		const string get_value(void) const noexcept								 ;

		static const string get_attr (const string &param						);
		static const string get_attr (const char *param, string::size_type _size);
		static const string get_value(const string &param						);
		static const string get_value(const char *param, string::size_type _size);

	private:
		string params;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_PARAM_HPP__*/

