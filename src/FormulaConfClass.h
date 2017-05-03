/*----- PROTECTED REGION ID(FormulaConfClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        FormulaConfClass.h
//
// description : Include for the FormulaConf root class.
//               This class is the singleton class for
//                the FormulaConf device class.
//               It contains all properties and methods which the 
//               FormulaConf requires only once e.g. the commands.
//
// project :     FormulaConf
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author: graziano $
//
// $Revision: 1.7 $
// $Date: 2017-04-13 08:10:22 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef FormulaConfClass_H
#define FormulaConfClass_H

#include <tango.h>
#include <FormulaConf.h>


/*----- PROTECTED REGION END -----*/	//	FormulaConfClass.h


namespace FormulaConf_ns
{
/*----- PROTECTED REGION ID(FormulaConfClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	FormulaConfClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute Version class definition
class VersionAttrib: public Tango::Attr
{
public:
	VersionAttrib():Attr("Version",
			Tango::DEV_STRING, Tango::READ) {};
	~VersionAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_Version(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_Version_allowed(ty);}
};

//	Attribute DevicesStatus class definition
class DevicesStatusAttrib: public Tango::SpectrumAttr
{
public:
	DevicesStatusAttrib():SpectrumAttr("DevicesStatus",
			Tango::DEV_STRING, Tango::READ, 5000) {};
	~DevicesStatusAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_DevicesStatus(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_DevicesStatus_allowed(ty);}
};


//=========================================
//	Define classes for dynamic attributes
//=========================================
//	Attribute BoolScalarDyn class definition
class BoolScalarDynAttrib: public Tango::Attr
{
public:
	BoolScalarDynAttrib(const string &att_name):Attr(att_name.c_str(), 
			Tango::DEV_BOOLEAN, Tango::READ) {};
	~BoolScalarDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_BoolScalarDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_BoolScalarDyn_allowed(ty);}
};

//	Attribute DoubleScalarDyn class definition
class DoubleScalarDynAttrib: public Tango::Attr
{
public:
	DoubleScalarDynAttrib(const string &att_name):Attr(att_name.c_str(), 
			Tango::DEV_DOUBLE, Tango::READ) {};
	~DoubleScalarDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_DoubleScalarDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_DoubleScalarDyn_allowed(ty);}
};

//	Attribute LongScalarDyn class definition
class LongScalarDynAttrib: public Tango::Attr
{
public:
	LongScalarDynAttrib(const string &att_name):Attr(att_name.c_str(), 
			Tango::DEV_LONG, Tango::READ) {};
	~LongScalarDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_LongScalarDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_LongScalarDyn_allowed(ty);}
};

//	Attribute StringSpectrumDyn class definition
class StringSpectrumDynAttrib: public Tango::SpectrumAttr
{
public:
	StringSpectrumDynAttrib(const string &att_name):SpectrumAttr(att_name.c_str(), 
			Tango::DEV_STRING, Tango::READ, 1000) {};
	~StringSpectrumDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_StringSpectrumDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_StringSpectrumDyn_allowed(ty);}
};

//	Attribute BoolSpectrumDyn class definition
class BoolSpectrumDynAttrib: public Tango::SpectrumAttr
{
public:
	BoolSpectrumDynAttrib(const string &att_name):SpectrumAttr(att_name.c_str(), 
			Tango::DEV_BOOLEAN, Tango::READ, 1000) {};
	~BoolSpectrumDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_BoolSpectrumDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_BoolSpectrumDyn_allowed(ty);}
};

//	Attribute DoubleSpectrumDyn class definition
class DoubleSpectrumDynAttrib: public Tango::SpectrumAttr
{
public:
	DoubleSpectrumDynAttrib(const string &att_name):SpectrumAttr(att_name.c_str(), 
			Tango::DEV_DOUBLE, Tango::READ, 1000) {};
	~DoubleSpectrumDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_DoubleSpectrumDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_DoubleSpectrumDyn_allowed(ty);}
};

//	Attribute LongSpectrumDyn class definition
class LongSpectrumDynAttrib: public Tango::SpectrumAttr
{
public:
	LongSpectrumDynAttrib(const string &att_name):SpectrumAttr(att_name.c_str(), 
			Tango::DEV_LONG, Tango::READ, 1000) {};
	~LongSpectrumDynAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<FormulaConf *>(dev))->read_LongSpectrumDyn(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<FormulaConf *>(dev))->is_LongSpectrumDyn_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command GetFormulaValues class definition
class GetFormulaValuesClass : public Tango::Command
{
public:
	GetFormulaValuesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetFormulaValuesClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetFormulaValuesClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<FormulaConf *>(dev))->is_GetFormulaValues_allowed(any);}
};


/**
 *	The FormulaConfClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  FormulaConfClass : public Tango::DeviceClass
#else
class FormulaConfClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(FormulaConfClass::Additionnal DServer data members) ENABLED START -----*/

	
	/*----- PROTECTED REGION END -----*/	//	FormulaConfClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static FormulaConfClass *init(const char *);
		static FormulaConfClass *instance();
		~FormulaConfClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		FormulaConfClass(string &);
		static FormulaConfClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	FormulaConf_H
