# E_PD_Dpv1Error

## Library
tcplclib_tc2_iofunctions

## Category
Motion Control

1. [TwinCAT 3 PLC Lib: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
2. [Data Types](ms-xhelp:///?Id=beckhoff-399b-416f-800e-abbd758eb40a)
3. E\_PD\_Dpv1Error

# E\_PD\_Dpv1Error

E\_PD\_Dpv1Error lists the DPV1-Error IDs:

```
TYPE E_PD_Dpv1Error :  
(  
    ePD_Err_ParamNumber               := 0,(* Unzulässige Parameternummer *)  
    ePD_Err_ParamReadOnly             := 1,(* Parameterwert nicht änderbar *)  
    ePD_Err_ValueOutOfRange           := 2,(* Untere oder obere Wertgrenze überschritten *)  
    ePD_Err_InvalidSubIndex           := 3,(* Fehlerhafter Subindex *)  
    ePD_Err_NoArray                   := 4,(* Kein Array *)  
    ePD_Err_WrongDataType             := 5,(* Falscher Datentyp *)  
    ePD_Err_OnlyResetPermitted        := 6,(* Kein Setzen errlaubt (nur Rücksetzen) *)  
    ePD_Err_DescNotChangable          := 7,(* Beschreibungselement nicht änderbar *)  
    ePD_Err_DescNotFound              := 9,(* Beschreibungselement nicht vorhanden *)  
    ePD_Err_NoPermissionToChange      := 11,(* Keine Bedienhoheit *)  
    ePD_Err_NoTextArray               := 15,(* Kein Textarray vorhanden *)  
    ePD_Err_JobNotExecutable          := 17,(* Auftrag wegen Betriebszustand nicht ausführbar *)  
    ePD_Err_ValueInvalid              := 20,(* Wert unzulässig *)  
    ePD_Err_ResponseToLong            := 21,(* Antwort zu lang *)  
    ePD_Err_ParamAddrInvalid          := 22,(* Parameteradresse unzulässig *)  
    ePD_Err_FormatInvalid             := 23,(* Format unzulässig *)  
    ePD_Err_NumOfValuesInvalid        := 24,(* Anzahl Werte nicht konsistent *)  
    ePD_Err_DriveObjNotExisting       := 25,(* Antriebsobjekt existiert nicht *)  
    ePD_Err_ParamDeactivated          := 101,(* Parameter momentan deaktiviert *)  
    ePD_Err_ParamNoWrIfEnabled        := 107,(* Kein Schreibzugriff bei freigegebenem Regler *)  
    ePD_Err_ParamInvalidUnit          := 108,(* Unbekannte Einheit *)  
    ePD_Err_ParamNoWrIfNotInitFbk     := 109,(* Schreibzugriff nur in Inbetriebnahmezustand Geber *)  
    ePD_Err_ParamWrIfInitMtr          := 110,(* Schreibzugriff nur in Inbetriebnahmezustand Motor *)  
    ePD_Err_ParamWrIfInitDrv          := 111,(* Schreibzugriff nur in Inbetriebnahmezustand Leistungsteil *)  
    ePD_Err_ParamWrIfFastInit         := 112,(* Schreibzugriff nur in Schnellinbetriebnahme *)  
    ePD_Err_ParamWrIfReady            := 113,(* Schreibzugriff nur in Bereit *)  
    ePD_Err_ParamWrIfInitParamReset   := 114,(* Schreibzugriff nur in Inbetriebnahmezustand Parameterreset *)  
    ePD_Err_ParamWrIfInitSafety       := 115,(* Schreibzugriff nur in Inbetriebnahmezustand Safety *)  
    ePD_Err_ParamWrIfInitTechApp      := 116,(* Schreibzugriff nur in Inbetriebnahmezustand Tech.Appl./Einheiten *)  
    ePD_Err_ParamWrIfInit             := 117,(* Schreibzugriff nur in Inbetriebnahmezustand *)  
    ePD_Err_ParamWrIfInitDwnLd        := 118,(* Schreibzugriff nur in Inbetriebnahmezustand Download *)  
    ePD_Err_ParamNoWrtIfDwnLd         := 119,(* Darf im Download nicht geschrieben werden *)  
    ePD_Err_ParamWrIfInitDrvCfg       := 120,(* Schreibzugriff nur in Inbetriebnahmezustand Antriebskonfiguration *)  
    ePD_Err_ParamWrIfInitSetDrvType   := 121,(* Schreibzugriff nur in Inbetriebnahmezustand Festlegung Antriebstyp *)  
    ePD_Err_ParamWrIfInitDatasetCfg   := 122,(* Schreibzugriff nur in Inbetriebnahmezustand Datensatz-Basiskonfiguration *)  
    ePD_Err_ParamWrIfInitDevCfg       := 123,(* Schreibzugriff nur in Inbetriebnahmezustand Gerätekonfiguration *)  
    ePD_Err_ParamWrIfInitDevDwnLd     := 124,(* Schreibzugriff nur in Inbetriebnahmezustand Gerätedownload *)  
    ePD_Err_ParamWrIfInitDevPrmReset  := 125,(* Schreibzugriff nur in Inbetriebnahmezustand Geräteparameterreset *)  
    ePD_Err_ParamWrIfInitDevReady     := 126,(* Schreibzugriff nur in Inbetriebnahmezustand Gerät bereit *)  
    ePD_Err_ParamWrIfInitDevice       := 127,(* Schreibzugriff nur in Inbetriebnahmezustand Gerät *)  
    ePD_Err_ParamNoWriteIfDwnLd       := 129,(* darf im Download nicht geschrieben werden *)  
    ePD_Err_CtrlTakeOverBlocked       := 130,(* Übernahme der Steuerungshoheit über BICO gesperrt *)  
    ePD_Err_ParamBicoSetInvalid       := 131,(* gewünschte BICO-Verschaltung unmöglich *)  
    ePD_Err_ParamChangeBlocked        := 132,(* Parameteränderung gesperrt *)  
    ePD_Err_ParamNoAccessDefined      := 133,(* Keine Zugriffsmethode definiert *)  
    ePD_Err_BelowDefinedMinimum       := 200,(* Unterhalb aktuell gültiger Grenze *)  
    ePD_Err_AboveDefinedMaximum       := 201,(* Oberhalb aktuell gültiger Grenze *)  
    ePD_Err_WriteNotPermitted         := 204(* Schreiben nicht erlaubt *)  
);  
END_TYPE
```

## Requirements

| Development environment | Target platform | IO hardware | PLC libraries to be integrated (category group) |
| --- | --- | --- | --- |
| TwinCAT v3.1.0 | PC or CX (x86, x64, ARM) | Beckhoff FC310x PCI, CX1500-M310, EL6731, EL6632 | Tc2\_IoFunctions (IO) |

[TwinCAT 3 | PLC Library: Tc2\_IoFunctions](ms-xhelp:///?Id=beckhoff-89f3-4b36-bb70-6247b05e611b)
