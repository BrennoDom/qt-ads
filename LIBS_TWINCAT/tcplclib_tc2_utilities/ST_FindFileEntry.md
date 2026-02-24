# ST_FindFileEntry

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_FindFileEntry

This data type is used by the file search function blocks: [FB\_EnumFindFileEntry](ms-xhelp:///?Id=beckhoff-010e-4df6-9917-0f23097681b4) and [FB\_EnumFindFileList](ms-xhelp:///?Id=beckhoff-1b2b-42a1-91ba-e32a06ee7247).

```
TYPE ST_FindFileEntry :  
STRUCT  
    sFileName          : T_MaxString;  
    sAlternateFileName : STRING(13);  
    fileAttributes     : ST_FileAttributes;  
    fileSize           : T_ULARGE_INTEGER;  
    creationTime       : T_FILETIME;  
    lastAccessTime     : T_FILETIME;  
    lastWriteTime      : T_FILETIME;  
END_STRUCT  
END_TYPE
```

**sFileName**: Zero-terminated string with the name of the file or directory (type: T\_MaxString).

**sAlternateFileName**: Zero-terminated string with the alternative name of the file or directory in conventional 8.3 format (filename.ext).

**fileAttributes**: Structure with file/directory attributes (type: [ST\_FileAttributes](ms-xhelp:///?Id=beckhoff-da81-4b7d-98c2-94a02d708f52)).

**fileSize**: Byte size of the file (64-bit number, type: [T\_ULARGE\_INTEGER](ms-xhelp:///?Id=beckhoff-095b-44a6-889e-3a69ee85aee0)).

**creationTime**: The structure variable indicates when the file or directory was created (type: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)).

**lastAccessTime**: For a file the structure indicates when it was last accessed (read or write) (type: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)). For a directory the structure indicates when it was created.

**lastWriteTime**: For a file the structure indicates the time of the last write access (type: [T\_FILETIME](ms-xhelp:///?Id=beckhoff-0450-4829-bf49-af9e07e7176d)). For a directory the structure indicates when it was created.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
