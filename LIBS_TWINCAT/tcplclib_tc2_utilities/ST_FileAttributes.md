# ST_FileAttributes

## Library
tcplclib_tc2_utilities

## Category
Motion Control

# ST\_FileAttributes

File or directory attributes.

```
TYPE ST_FileAttributes :  
STRUCT  
    bReadOnly          : BOOL;(* FILE_ATTRIBUTE_READONLY *)  
    bHidden            : BOOL;(* FILE_ATTRIBUTE_HIDDEN *)  
    bSystem            : BOOL;(* FILE_ATTRIBUTE_SYSTEM *)  
    bDirectory         : BOOL;(* FILE_ATTRIBUTE_DIRECTORY *)  
    bArchive           : BOOL;(* FILE_ATTRIBUTE_ARCHIVE *)  
    bDevice            : BOOL;(* FILE_ATTRIBUTE_DEVICE. Under CE: FILE_ATTRIBUTE_INROM or FILE_ATTRIBUTE_ENCRYPTED *)  
    bNormal            : BOOL;(* FILE_ATTRIBUTE_NORMAL *)  
    bTemporary         : BOOL;(* FILE_ATTRIBUTE_TEMPORARY *)  
    bSparseFile        : BOOL;(* FILE_ATTRIBUTE_SPARSE_FILE *)  
    bReparsePoint      : BOOL;(* FILE_ATTRIBUTE_REPARSE_POINT *)  
    bCompressed        : BOOL;(* FILE_ATTRIBUTE_COMPRESSED *)  
    bOffline           : BOOL;(* FILE_ATTRIBUTE_OFFLINE. Under CE: FILE_ATTRIBUTE_ROMSTATICREF *)  
    bNotContentIndexed : BOOL;(* FILE_ATTRIBUTE_NOT_CONTENT_INDEXED. Under CE: FILE_ATTRIBUTE_ROMMODULE *)  
    bEncrypted         : BOOL;(* FILE_ATTRIBUTE_ENCRYPTED *)  
END_STRUCT  
END_TYPE
```

**bReadOnly**: The file or directory only has read access. The file can be read by applications, but it cannot be written to or deleted. In the case of directories, these cannot be deleted by applications.

**bHidden**: The file or directory is hidden and is not shown in a standard listing.

**bSystem**: The file or directory is part of the operating system or is exclusively used by the operating system.

**bDirectory**: This attribute can be used to identify a directory.

**bArchive**: The file or directory belongs to the archive. Applications use this attribute in order to tag files for backup or deletion.

**bDevice**: Reserved.

**bNormal**: The file or directory has no other attributes set. This attribute is only valid if is used exclusively.

**bTemporary**: The file is only used temporarily for storing data.

**bSparseFile**: The file is a slimmed-down file.

**bReparsePoint**: A "reparse point" was associated with the file or directory.

**bCompressed**: The file or directory is compressed. The file contains compressed data. In the case of a directory, compacting is active by default for new files or subdirectories.

**bOffline**: The file is not always available.

**bNotContentIndexed**: The file is not indexed by the indexing service.

**bEncrypted**: The file or directory is encrypted.

## Requirements

| Development environment | Target platform | PLC libraries to be integrated (category group) |
| --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Tc2\_Utilities (System) |
