#include "sierrachart.h"
SCDLLName("MethodTrades - Study Input FLOAT Change on Symbol Change")

/* 
Author: https://github.com/methodtrades
Big thanks to Luda on Trader Network Lounge Discord
This study is the same as my STRING study, but is for editing single numeric value fields,
not text string fields. Ex: "1" (Float) vs "1,2,3" (string)
*/

SCSFExport scsf_StudyInputChangeSymChange(SCStudyInterfaceRef sc)
{
    // Define study inputs
    SCInputRef Input_StudyID = sc.Input[0];
    SCInputRef Input_StudyInputID = sc.Input[1];
    SCInputRef Input_0 = sc.Input[2];
    SCInputRef Input_0_Value = sc.Input[3];
    SCInputRef Input_1 = sc.Input[4];
    SCInputRef Input_1_Value = sc.Input[5];
    SCInputRef Input_2 = sc.Input[6];
    SCInputRef Input_2_Value = sc.Input[7];
    SCInputRef Input_3 = sc.Input[8];
    SCInputRef Input_3_Value = sc.Input[9];
    SCInputRef Input_4 = sc.Input[10];
    SCInputRef Input_4_Value = sc.Input[11];
    SCInputRef Input_5 = sc.Input[12];
    SCInputRef Input_5_Value = sc.Input[13];
    SCInputRef Input_6 = sc.Input[14];
    SCInputRef Input_6_Value = sc.Input[15];
    SCInputRef Input_7 = sc.Input[16];
    SCInputRef Input_7_Value = sc.Input[17];
    SCInputRef Input_8 = sc.Input[18];
    SCInputRef Input_8_Value = sc.Input[19];
    SCInputRef Input_9 = sc.Input[20];
    SCInputRef Input_9_Value = sc.Input[21];
    SCInputRef Input_10 = sc.Input[22];
    SCInputRef Input_10_Value = sc.Input[23];
    SCInputRef Input_11 = sc.Input[24];
    SCInputRef Input_11_Value = sc.Input[25];
    SCInputRef Input_12 = sc.Input[26];
    SCInputRef Input_12_Value = sc.Input[27];
    SCInputRef Input_13 = sc.Input[28];
    SCInputRef Input_13_Value = sc.Input[29];
    SCInputRef Input_14 = sc.Input[30];
    SCInputRef Input_14_Value = sc.Input[31];
    SCInputRef Input_15 = sc.Input[32];
    SCInputRef Input_15_Value = sc.Input[33];

    
    
    if (sc.SetDefaults)
    {
        // Set default settings
        sc.GraphRegion = 0;
        sc.GraphName = "Study Input Change on Symbol Change";
        sc.StudyDescription = "Adjusts the input of another study based on the symbol.";
        sc.AutoLoop = 0;  // Disable AutoLoop

        // Initialize study inputs
        Input_StudyID.Name = "Study ID";
        Input_StudyID.SetStudyID(4);

        Input_StudyInputID.Name = "Study Input ID";
        Input_StudyInputID.SetInt(1);

        Input_0.Name= "Symbol 0";
        Input_0.SetString("DEFAULT");
        Input_0_Value.Name = "Symbol 0 Value";
        Input_0_Value.SetFloat(2500.0);

        Input_1.Name= "Symbol 1";
        Input_1.SetString("AAPL_MBO");
        Input_1_Value.Name = "Symbol 1 Value";
        Input_1_Value.SetFloat(7500);

        Input_2.Name= "Symbol 2";
        Input_2.SetString("TSLA_MBO");
        Input_2_Value.Name = "Symbol 2 Value";
        Input_2_Value.SetFloat(2000.0);

        Input_3.Name= "Symbol 3";
        Input_3.SetString("Symbol");
        Input_3_Value.Name = "Symbol 3 Value";
        Input_3_Value.SetFloat(5.0);

        Input_4.Name= "Symbol 4";
        Input_4.SetString("Symbol");
        Input_4_Value.Name = "Symbol 4 Value";
        Input_4_Value.SetFloat(5.0);

        Input_5.Name= "Symbol 5";
        Input_5.SetString("Symbol");
        Input_5_Value.Name = "Symbol 5 Value";
        Input_5_Value.SetFloat(15.0);

        Input_6.Name= "Symbol 6";
        Input_6.SetString("Symbol");
        Input_6_Value.Name = "Symbol 6 Value";
        Input_6_Value.SetFloat(15.0);
        
        Input_7.Name= "Symbol 7";
        Input_7.SetString("Symbol");
        Input_7_Value.Name = "Symbol 7 Value";
        Input_7_Value.SetFloat(15.0);
        
        Input_8.Name= "Symbol 8";
        Input_8.SetString("Symbol");
        Input_8_Value.Name = "Symbol 8 Value";
        Input_8_Value.SetFloat(15.0);
        
        Input_9.Name= "Symbol 9";
        Input_9.SetString("Symbol");
        Input_9_Value.Name = "Symbol 9 Value";
        Input_9_Value.SetFloat(15.0);
        
        Input_10.Name= "Symbol 10";
        Input_10.SetString("Symbol");
        Input_10_Value.Name = "Symbol 10 Value";
        Input_10_Value.SetFloat(15.0);
        
        Input_11.Name= "Symbol 11";
        Input_11.SetString("Symbol");
        Input_11_Value.Name = "Symbol 11 Value";
        Input_11_Value.SetFloat(15.0);
        
        Input_12.Name= "Symbol 12";
        Input_12.SetString("Symbol");
        Input_12_Value.Name = "Symbol 12 Value";
        Input_12_Value.SetFloat(15.0);
        
        Input_13.Name= "Symbol 13";
        Input_13.SetString("Symbol");
        Input_13_Value.Name = "Symbol 13 Value";
        Input_13_Value.SetFloat(15.0);
        
        Input_14.Name= "Symbol 14";
        Input_14.SetString("Symbol");
        Input_14_Value.Name = "Symbol 14 Value";
        Input_14_Value.SetFloat(15.0);
        return;
    }

    // Only run this code on a full recalculation (e.g., symbol switch event)
    if (!sc.IsFullRecalculation)
    {
        return;
    }

    // Get the Study ID
    int StudyID = Input_StudyID.GetInt();
    // Adjust the input of the Study based on the symbol
    if (sc.Symbol == Input_1.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_1_Value.GetInt()); 
    }
    else if (sc.Symbol == Input_2.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_2_Value.GetInt());
    }
    else if (sc.Symbol == Input_3.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_3_Value.GetInt());
    }
    else if (sc.Symbol == Input_4.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_4_Value.GetInt());
    }
    else if (sc.Symbol == Input_5.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_5_Value.GetInt());
    }
        else if (sc.Symbol == Input_6.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_6_Value.GetInt());
    }
        else if (sc.Symbol == Input_7.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_7_Value.GetInt());
    }
        else if (sc.Symbol == Input_8.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_8_Value.GetInt());
    }
        else if (sc.Symbol == Input_9.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_9_Value.GetInt());
    }
        else if (sc.Symbol == Input_10.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_10_Value.GetInt());
    }
        else if (sc.Symbol == Input_11.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_11_Value.GetInt());
    }
        else if (sc.Symbol == Input_12.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_12_Value.GetInt());
    }
        else if (sc.Symbol == Input_13.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_13_Value.GetInt());
    }
        else if (sc.Symbol == Input_14.GetString())
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_14_Value.GetInt());
    }
    
    else 
    {
        sc.SetChartStudyInputInt(sc.ChartNumber, StudyID, Input_StudyInputID.GetInt() - 1, Input_0_Value.GetInt());
    }

}
