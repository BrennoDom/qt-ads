# ST_BA_SeqLink / ST_BA_SeqLinkData

## Library
tcplclib_tc3_ba_common

## Category
Motion Control

# ST\_BA\_SeqLink / ST\_BA\_SeqLinkData

Structure of the data and command exchange between the control function block [FB\_BA\_SeqLink](ms-xhelp:///?Id=beckhoff-d060-4ce8-9edc-114c51dff6a8) and the sequence controllers [FB\_BA\_SeqCtrl](ms-xhelp:///?Id=beckhoff-5f1e-4dd3-b036-9ec1a0438ff2).

This structure has to be created once per sequence control:

```
stSeqLink : ST_BA_SeqLink;
```

Within this structure, a further field structure is declared automatically, through which the sequence link function block and the individual sequence controllers exchange all relevant data. Each sequence controller writes its data into the field element corresponding to its ordinal number (entry at input *diMyNum* at the sequence controller function block). It is always the complete structure with all field elements that is linked to the function blocks.

The structures have the following setup:

```
TYPE ST_BA_SeqLink :  
STRUCT  
  arrSeqLinkData : ARRAY[1..16] OF ST_BA_SeqLinkData;  
  diCurCtrl      : DINT;  
  bSeqActv       : BOOL;  
END_STRUCT  
END_TYPE
```

**arrSeqLinkData:** Parameters of the individual sequence controllers. See below for a description of the structure *ST\_BA\_SeqLinkData.*

**diCurCtrl:** from FB\_BA\_SeqLink: Specification of current sequence controllers.

**bSeqActv:** The sequence control is enabled and active.

```
TYPE ST_BA_SeqLinkData:  
STRUCT  
  lrY         : LREAL;  
  lrYMin      : LREAL;  
  lrYMax      : LREAL;  
  lrW         : LREAL;  
  bActn       : BOOL;  
  bOp         : BOOL;  
  bPresence   : BOOL;  
  bErrDouble  : BOOL;  
  diCurCtrl   : DINT;  
END_STRUCT  
END_TYPE
```

**lrY:** from FB\_BA\_SeqCtrl: Transfer of current control value.

**lrYMin:** from FB\_BA\_SeqCtrl: Transfer of minimum control value.

**lrYMax:** from FB\_BA\_SeqCtrl: Transfer of maximum control value.

**lrW:** from FB\_BA\_SeqCtrl: Transfer of current set value.

**bActn:** from FB\_BA\_SeqCtrl: Transfer of inverse direction of action (*bActn* = FALSE: heating mode - *bActn* = TRUE: cooling mode).

**bOp:** from FB\_BA\_SeqCtrl: Sequence controller is enabled, i.e. its input *bEn* is set to TRUE.

**bPresence:** from FB\_BA\_SeqCtrl: Checkbit, see below

**bErrDouble:** from FB\_BA\_SeqCtrl: Error during number verification: Two or more sequence controllers exist with the same ordinal number *diMyNum*.

**diCurCtrl:** from FB\_BA\_SeqLink: Specification of current sequence controllers.

## **Note regarding check bit:**

Every sequence controller sets the *bPresence* flag in the structure that is valid for itself. If it is already set, however, then it is mandatory for *diMyNum* to be assigned twice and two sequence controllers access the same structure. After the evaluation, the sequence link function block resets all check bits, so that this test takes place cyclically. This means that an error can automatically be rectified via an online change, and new sequence controllers can be added, if required.

## Requirements

| Development environment | Required library | Necessary function |
| --- | --- | --- |
| TwinCAT3.1 4022.16 | Tc3Building Automation Common from V1.0.4.3 | TF8040 | TwinCAT Building Automation from V1.0.5.0 |
