# FB_MDP_SplitErrorId

## Library
tcplclib_tc2_mdp

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_MDP (IPC diagnostics)](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
2. [Function blocks](ms-xhelp:///?Id=beckhoff-23a0-4133-855a-a7677f5f17f9)
3. [Generic](ms-xhelp:///?Id=beckhoff-9c1b-41c3-8a15-8a7ba816748e)
4. FB\_MDP\_SplitErrorId

# FB\_MDP\_SplitErrorId

![34377519](/tcplclib_tc2_mdp/1033/Images/gif/178799883__en-US__Web.gif)

The function block enables the *nErrID* to be split into an [error group](ms-xhelp:///?Id=beckhoff-267d-40a2-917e-1b453e1e2694) and a specific error code.

Accordingly, this function block can be referred to for the simplified evaluation of *nErrID*.

## VAR\_INPUT

```
VAR_INPUT  
    nErrID : UDINT;  
END_VAR
```

**nErrID**: nErrID is specified as an input on the function block. This 4-byte variable corresponds to the output nErrID on an MDP function block.

## VAR\_OUTPUT

```
VAR_OUTPUT  
    eErrGroup : E_MDP_ErrGroup; (* type of transmitted error code *)  
    nErrCode  : UINT;           (* error code [see specific error type table] *)  
END_VAR
```

**eErrGroup**: The output eErrGroup corresponds to a value of the enumeration [E\_MDP\_ErrGroup](ms-xhelp:///?Id=beckhoff-267d-40a2-917e-1b453e1e2694). It is possible with the aid of the error group to distinguish the type of error or the source of error concerned.

**nErrCode**: The error code is specific for each error group.

## Requirements

| Development environment | Target platform | PLC libraries to include |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_MDP |

[TwinCAT 3 | PLC Library:Tc2\_MDP](ms-xhelp:///?Id=beckhoff-346f-40a1-8ce4-910757d45010)
