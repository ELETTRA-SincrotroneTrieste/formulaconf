/*----- PROTECTED REGION ID(FormulaConf.h) ENABLED START -----*/
//=============================================================================
//
// file :        FormulaConf.h
//
// description : Include file for the FormulaConf class
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
// $Revision: 1.15 $
// $Date: 2017-04-13 08:10:22 $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef FormulaConf_H
#define FormulaConf_H

#include <tango.h>

#define MAX_ATTR_SIZE 1000

#include <boost/version.hpp>

#if BOOST_VERSION  < 103600
#include <boost/spirit/tree/ast.hpp>					//for ast parse trees (in tree_formula)
#else
#include <boost/spirit/include/classic_ast.hpp>			//for ast parse trees (in tree_formula)
#endif

#include "readthread.h"

#if BOOST_VERSION  < 103600
typedef std::string::iterator  iterator_t;
typedef boost::spirit::node_val_data_factory<unsigned int> factory_t;		//want a modified node to contain an unsigned int value
typedef boost::spirit::tree_match<iterator_t, factory_t> parse_tree_match_t;
typedef boost::spirit::tree_parse_info<iterator_t, factory_t>    tree_parse_info_t;
#else
typedef std::string::iterator  iterator_t;
typedef boost::spirit::classic::node_val_data_factory<unsigned int> factory_t;		//want a modified node to contain an unsigned int value
typedef boost::spirit::classic::tree_match<iterator_t, factory_t> parse_tree_match_t;
typedef boost::spirit::classic::tree_parse_info<iterator_t, factory_t>    tree_parse_info_t;
#endif

typedef parse_tree_match_t::tree_iterator iter_t;

/*----- PROTECTED REGION END -----*/	//	FormulaConf.h

/**
 *  FormulaConf class description:
 *    Configurable formula
 */

namespace FormulaConf_ns
{
/*----- PROTECTED REGION ID(FormulaConf::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations
class FormulaConf;
/*
 * event callback
 */
class EventCallBack : public Tango::CallBack {
	public:
		EventCallBack(void);
		~EventCallBack(void);
		void push_event(Tango::EventData* ev);
		void init(FormulaConf *p);
	private:
	FormulaConf *mydevice;
	//vector<FormulaConf *> mydevices;
};

typedef struct
{
	string remote_name;
	string remote_device_name;
	string remote_attr_name;
	Tango::DeviceProxy *remote_device;
	unsigned int eid;
	vector<double> value;	//double for any type of Attribute (except DevString)
	string value_string;	//added for DevString attributes
	Tango::AttrQuality 		quality;
	struct timespec last_read;
	int stat_index;
	bool event_error;		//if event error, goes in polling
	struct timespec last_event_rx;
	vector<string> loc_attr_name;	//list of local attributes interested in this event
} remote_dev_t;

typedef struct
{
	string formula;
	tree_parse_info_t formula_tree;
	unsigned int attr_index;
	string descr;
	vector<string> remote_name;	//list of remote attrs in this formula
	string type;
	bool first_push;
	//Tango::DevBoolean val;
	string attr_values;

} attr_desc_t;

typedef struct
{
	Tango::DevBoolean val[MAX_ATTR_SIZE];
	Tango::DevBoolean old_val[MAX_ATTR_SIZE];
	Tango::DevDouble val_d[MAX_ATTR_SIZE];
	Tango::DevDouble old_val_d[MAX_ATTR_SIZE];
	Tango::DevLong val_l[MAX_ATTR_SIZE];
	Tango::DevLong old_val_l[MAX_ATTR_SIZE];

} attr_val_t;

typedef struct
{
	vector<Tango::DevBoolean> val_b;
	vector<string> val_s;
} rem_val_t;

typedef struct
{
	char val[MAX_ATTR_SIZE][128];

} attr_val_string_t;

typedef struct
{
	string remote_cmd_name;
	int cmd_code;
	int cmd_offset;
	int cmd_offset2;
	int cmd_offset3;
	int cmd_offset4;
	string pass;

} cmd_desc_t;

/*----- PROTECTED REGION END -----*/	//	FormulaConf::Additional Class Declarations

class FormulaConf : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(FormulaConf::Data Members) ENABLED START -----*/

//	Add your own data members
	friend class CmdClass;
protected:

    map<string,vector<attr_desc_t> >   att_data;	//attr name->vector (for spectrum attr) of attr_desc_t (formula tree)
    vector<remote_dev_t> remote_devices;			//array of remote attributes (proxy, array of values)
    map<string,attr_val_t >   m_att_value;			//attr name->array of values (for set_value)


    void string_explode(string, string, vector<string>*);
    void init_attributeprop();
    void create_dynamic_attributes(vector<string> attr_config);

    double eval_formula(tree_parse_info_t tree, string attr_name, string &attr_values);
    double eval_expression(iter_t const& i, string attr_name, string &attr_values, uint32_t ev_ind=0); //throw (string &), std::out_of_range
    void find_device_formula(tree_parse_info_t tree, vector<string> & devs);
    void eval_node_device(iter_t const& i, vector<string> & devs);

    void extract_values(Tango::DeviceAttribute *attr_value, vector<double> &val, string &val_string);
    vector<remote_dev_t>::iterator find_events(string event_name) throw(string&);

    //Tango::DeviceProxy *lldevice;

    struct timespec last_read;

    map<string,cmd_desc_t>   cmd_data;

    char version_str[1024];
    char devices_status_str[3*MAX_ATTR_SIZE][2048];

    readthread *read_loop;
    friend class readthread;
    EventCallBack ecb;
    friend class EventCallBack;

    bool created_attr;
    int attr_index;
public:


/*----- PROTECTED REGION END -----*/	//	FormulaConf::Data Members

//	Device property data members
public:
	//	Attr_config_file:	File pathname containing configuration in the form:
	//  attr;attr_type;attr_name;attr_index;formula;description
	string	attr_config_file;
	//	Attr_config_prop:	Array of configuration strings in the form:
	//  attr;attr_type;attr_name;attr_index;formula;description
	vector<string>	attr_config_prop;
	//	Polling_period:	Period of polling thread in seconds. Set -1 to disable polling.
	Tango::DevDouble	polling_period;
	//	Read_timeout:	Timeout in seconds before forcing polling if enabled.
	Tango::DevDouble	read_timeout;

//	Attribute data members
public:
	Tango::DevString	*attr_Version_read;
	Tango::DevString	*attr_DevicesStatus_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FormulaConf(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	FormulaConf(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	FormulaConf(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~FormulaConf() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : FormulaConf::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute Version related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_Version(Tango::Attribute &attr);
	virtual bool is_Version_allowed(Tango::AttReqType type);
/**
 *	Attribute DevicesStatus related methods
 *	Description: Status of attributes involved in formulas with timestamp of last valid value, event status, polling status.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 5000
 */
	virtual void read_DevicesStatus(Tango::Attribute &attr);
	virtual bool is_DevicesStatus_allowed(Tango::AttReqType type);

//	Dynamic attribute methods
public:

	/**
	 *	Attribute BoolScalarDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevBoolean
	 *	Attr type:	Scalar
	 */
	virtual void read_BoolScalarDyn(Tango::Attribute &attr);
	virtual bool is_BoolScalarDyn_allowed(Tango::AttReqType type);
	void add_BoolScalarDyn_dynamic_attribute(string attname);
	void remove_BoolScalarDyn_dynamic_attribute(string attname);
	Tango::DevBoolean *get_BoolScalarDyn_data_ptr(string &name);
	map<string,Tango::DevBoolean>	   BoolScalarDyn_data;

	/**
	 *	Attribute DoubleScalarDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevDouble
	 *	Attr type:	Scalar
	 */
	virtual void read_DoubleScalarDyn(Tango::Attribute &attr);
	virtual bool is_DoubleScalarDyn_allowed(Tango::AttReqType type);
	void add_DoubleScalarDyn_dynamic_attribute(string attname);
	void remove_DoubleScalarDyn_dynamic_attribute(string attname);
	Tango::DevDouble *get_DoubleScalarDyn_data_ptr(string &name);
	map<string,Tango::DevDouble>	   DoubleScalarDyn_data;

	/**
	 *	Attribute LongScalarDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevLong
	 *	Attr type:	Scalar
	 */
	virtual void read_LongScalarDyn(Tango::Attribute &attr);
	virtual bool is_LongScalarDyn_allowed(Tango::AttReqType type);
	void add_LongScalarDyn_dynamic_attribute(string attname);
	void remove_LongScalarDyn_dynamic_attribute(string attname);
	Tango::DevLong *get_LongScalarDyn_data_ptr(string &name);
	map<string,Tango::DevLong>	   LongScalarDyn_data;

	/**
	 *	Attribute StringSpectrumDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevString
	 *	Attr type:	Spectrum max = 1000
	 */
	virtual void read_StringSpectrumDyn(Tango::Attribute &attr);
	virtual bool is_StringSpectrumDyn_allowed(Tango::AttReqType type);
	void add_StringSpectrumDyn_dynamic_attribute(string attname, Tango::DevString *ptr=NULL);
	void remove_StringSpectrumDyn_dynamic_attribute(string attname, bool free_it=true);
	Tango::DevString *get_StringSpectrumDyn_data_ptr(string &name);
	map<string,Tango::DevString *>	   StringSpectrumDyn_data;

	/**
	 *	Attribute BoolSpectrumDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevBoolean
	 *	Attr type:	Spectrum max = 1000
	 */
	virtual void read_BoolSpectrumDyn(Tango::Attribute &attr);
	virtual bool is_BoolSpectrumDyn_allowed(Tango::AttReqType type);
	void add_BoolSpectrumDyn_dynamic_attribute(string attname, Tango::DevBoolean *ptr=NULL);
	void remove_BoolSpectrumDyn_dynamic_attribute(string attname, bool free_it=true);
	Tango::DevBoolean *get_BoolSpectrumDyn_data_ptr(string &name);
	map<string,Tango::DevBoolean *>	   BoolSpectrumDyn_data;

	/**
	 *	Attribute DoubleSpectrumDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevDouble
	 *	Attr type:	Spectrum max = 1000
	 */
	virtual void read_DoubleSpectrumDyn(Tango::Attribute &attr);
	virtual bool is_DoubleSpectrumDyn_allowed(Tango::AttReqType type);
	void add_DoubleSpectrumDyn_dynamic_attribute(string attname, Tango::DevDouble *ptr=NULL);
	void remove_DoubleSpectrumDyn_dynamic_attribute(string attname, bool free_it=true);
	Tango::DevDouble *get_DoubleSpectrumDyn_data_ptr(string &name);
	map<string,Tango::DevDouble *>	   DoubleSpectrumDyn_data;

	/**
	 *	Attribute LongSpectrumDyn related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevLong
	 *	Attr type:	Spectrum max = 1000
	 */
	virtual void read_LongSpectrumDyn(Tango::Attribute &attr);
	virtual bool is_LongSpectrumDyn_allowed(Tango::AttReqType type);
	void add_LongSpectrumDyn_dynamic_attribute(string attname, Tango::DevLong *ptr=NULL);
	void remove_LongSpectrumDyn_dynamic_attribute(string attname, bool free_it=true);
	Tango::DevLong *get_LongSpectrumDyn_data_ptr(string &name);
	map<string,Tango::DevLong *>	   LongSpectrumDyn_data;

	//--------------------------------------------------------
	/**
	 *	Method      : FormulaConf::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command GetFormulaValues related method
	 *	Description: Return actual values of attribute involved in a formula as:
	 *               attr_name=value;attr_name=value;...
	 *
	 *	@param argin Formula name
	 *	@returns Formula values as: attr_name=value;attr_name=value;...
	 */
	virtual Tango::DevVarStringArray *get_formula_values(Tango::DevString argin);
	virtual bool is_GetFormulaValues_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : FormulaConf::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(FormulaConf::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
	//--------------------------------------------------------
	/**
	 *	Method      : FormulaConf::remove_dynamic_attributes()
	 *	Description : Remove dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void remove_dynamic_attributes();

/*----- PROTECTED REGION END -----*/	//	FormulaConf::Additional Method prototypes
};

/*----- PROTECTED REGION ID(FormulaConf::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	FormulaConf::Additional Classes Definitions

}	//	End of namespace

#endif   //	FormulaConf_H
