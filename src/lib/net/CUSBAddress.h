#pragma once

#include "base/String.h"
#include "common/basic_types.h"
#include "BaseAddress.h"

class CUSBAddress : public BaseAddress
{
public:
	/*!
	Constructs the invalid address
	*/
	CUSBAddress(void);

	/*!
	Construct device path. Consist of Vendor ID (nnVID), Product ID (nnPID), 
	in endpoint number (nnBulkIN), out endpoint number (nnBulkOUT),
	bus number (nnBus), device number (nnDeviceOnBus)
	nnBus, nnDeviceOnBus could be entered here optionally
	*/
	CUSBAddress(const UInt16 nnVID, const UInt16 nnPID, const UInt8 nnBulkIN, 
		const UInt8 nnBulkOUT, const UInt8 nnBus, const UInt8 nnDeviceOnBus);

	/*!
	Construct device path. Consists of string values of Vendor ID, 
	Product ID, in endpoint number, out endpoint number, bus number, 
	device number (nnDeviceOnBus)
	nnBus, nnDeviceOnBus could be entered here optionally
	*/
	CUSBAddress(const String& devicepath);

public:
	CUSBAddress(const CUSBAddress&);

	~CUSBAddress();

	CUSBAddress&			operator=(const CUSBAddress&);

	//@}
	//! @name accessors
	//@{

	//! Check address equality
	/*!
	Returns true if this address is equal to \p address.
	*/
	bool					operator==(const CUSBAddress& address) const;

	//! Check address inequality
	/*!
	Returns true if this address is not equal to \p address.
	*/
	bool					operator!=(const CUSBAddress& address) const;

	//! Check address validity
	/*!
	Returns true if this is not the invalid address.
	*/
	virtual bool			isValid() const;

	virtual AddressType 	getAddressType() const;

	virtual String			getName() const;

	virtual CUSBAddress* 	clone() const;

	//! Return Vendor ID
	UInt16 GetVID();
	//! Return Product ID
	UInt16 GetPID();
	//! Return Bilk In ID
	UInt8 GetIDBulkIN();
	//! Return Bulk Out ID
	UInt8 GetIDBulkOut();
	//! Return Bus ID
	UInt8 GetIDBus();
	//! Return Device ID on USB Bus
	UInt8 GetIDDeviceOnBus();
	/*! Return string contains hexadecimal Vendor ID, Product ID, in endpoint 
	number, out endpoint number, bus number, device number, divided by spaces
	*/
	String getUSBHostname() const;
	/*!
	Construct device path. Consists of string values of Vendor ID, 
	Product ID, in endpoint number, out endpoint number, bus number, 
	device number (nnDeviceOnBus)
	nnBus, nnDeviceOnBus could be entered here optionally
	If device path is invalid function will return false and
	
	*/
	bool setUSBHostName(const String& name);

	//@}

private:
	UInt16 nVID;
	UInt16 nPID;
	UInt8 nBulkIN;
	UInt8 nBulkOut;
	UInt8 nBus;
	UInt8 nDeviceOnBus;
};


