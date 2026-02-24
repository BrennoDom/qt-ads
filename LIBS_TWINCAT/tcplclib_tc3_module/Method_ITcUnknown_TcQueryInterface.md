# Method ITcUnknown:TcQueryInterface

## Library
tcplclib_tc3_module

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
2. [Appendix](ms-xhelp:///?Id=beckhoff-7a54-458a-984c-ff7aefcf1c19)
3. [Interfaces](ms-xhelp:///?Id=beckhoff-581c-4e1d-a450-dec7512fb73c)
4. [Interface ITcUnknown](ms-xhelp:///?Id=beckhoff-c839-4bdf-98ea-b60f82d20e77)
5. Method ITcUnknown:TcQueryInterface

# Method ITcUnknown:TcQueryInterface

Query of an interface pointer with regard to an interface that is given by interface ID (IID).

## Syntax

```
HRESULT TcQueryInterface(RITCID iid, PPVOID pipItf )
```

**iid**: (Type: RITCID) Interface IID.

**pipItf**: (PPVOID Type) pointer to interface pointer. Is set when the requested interface type is available from the corresponding instance.

## Return value

If successful, S\_OK ("0") or another positive value will be returned, cf. Return values. Extended messages refer in particular to the column HRESULT in [ADS Return Codes](ms-xhelp:///?Id=beckhoff-4780-452a-ab6b-bc4e8908f2c6).

If the demanded interface is not available, the method returns ADSERR\_DEVICE\_NOINTERFACE.

## Description

Query reference to an implemented interface by the IID. It is recommended to use smart pointers to initialize and hold interface pointers.   
  
**Variant 1:**

```
                                                                            HRESULT GetTraceLevel(ITcUnkown* ip, TcTraceLevel& tl)  
{  
    HRESULT hr = S_OK;  
    if (ip != NULL)  
    {  
        ITComObjectPtr spObj;  
        hr = ip->TcQueryInterface(spObj.GetIID(), &spObj);  
        if (SUCCEEDED(hr))  
        {  
            hr = spObj->TcGetObjPara(PID_TcTraceLevel, &tl, sizeof(tl));  
        }   
        return hr;  
    }  
}
```

The interface id associated with the smart pointer can be used as parameter in TcQueryInterface. The operator “&” will return pointer to internal interface pointer member of the smart pointer. Variant 1 assumes that interface pointer is initialized if TcQueryInterface indicates success. If scope is left the destructor of the smart pointer spObj releases the reference.   
  
**Variant 2:**

```
                                                          
HRESULT GetTraceLevel(ITcUnkown* ip, TcTraceLevel& tl)  
{  
    HRESULT hr = S_OK;  
    ITComObjectPtr spObj = ip;       
    if (spObj != NULL)  
    {  
        spObj->TcGetObjParam(PID_TcTraceLevel, &tl);  
    }   
    else  
    {  
        hr = ADS_E_NOINTERFACE;  
    }  
    return hr;  
}
```

When assigning interface pointer ip to smart pointer spObj method TcQueryInterface is implicitly called with IID\_ITComObject on the instance ip refers to. This results in shorter code, however it loses the original return code of TcQueryInterface.

[TwinCAT 3 | PLC Library:Tc3\_Module](ms-xhelp:///?Id=beckhoff-bcd3-40fe-aa49-602b4cdc62b7)
