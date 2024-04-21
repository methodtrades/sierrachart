#include "sierrachart.h"
#include <string>
#include <vector>
SCDLLName("Frozen Tundra - Auto NumBars Volume Multiplier")

/*
    Written by Frozen Tundra
    Modified by Method https://github.com/methodtrades
*/

SCSFExport scsf_AutoNumBarsVolMult(SCStudyInterfaceRef sc)
{
    SCString msg;
    SCInputRef i_TargetChart = sc.Input[1];
    SCInputRef i_NumBarCalc1 = sc.Input[2];
    SCInputRef i_NumBarCalc2 = sc.Input[3];
    
    SCInputRef Default_StockBoldSize = sc.Input[4];
    SCInputRef Default_StockMultiplier = sc.Input[5];
    SCInputRef Default_StockImbalanceMinimum = sc.Input[6];

    SCInputRef Default_FuturesBoldSize = sc.Input[7];
    SCInputRef Default_FuturesMultiplier = sc.Input[8];
    SCInputRef Default_FuturesImbalanceMinimum = sc.Input[9];

    SCInputRef Symbol1 = sc.Input[10];
    SCInputRef Symbol1_BoldSize = sc.Input[11];
    SCInputRef Symbol1_Multiplier = sc.Input[12];
    SCInputRef Symbol1_ImbalanceMinimum = sc.Input[13];

    if (sc.SetDefaults)
    {
        sc.GraphRegion = 0;
        sc.GraphShortName = "Auto NumBars VolMult";

        i_TargetChart.Name = "Select Number Bars Study";
        i_TargetChart.SetChartStudyValues(sc.ChartNumber,17);
        i_NumBarCalc1.Name = "Select NumBarCalc Delta Study";
        i_NumBarCalc1.SetChartStudyValues(sc.ChartNumber,20);
        i_NumBarCalc2.Name = "Select NumBarCalc Total Vol Study";
        i_NumBarCalc2.SetChartStudyValues(sc.ChartNumber,20);

        Default_StockBoldSize.Name= "Default Stock Bold Size";
        Default_StockBoldSize.SetFloat(10000);
        Default_StockMultiplier.Name= "Default Stock Multiplier";
        Default_StockMultiplier.SetCustomInputStrings("0;1;2;3");
        Default_StockImbalanceMinimum.Name= "Default Stock Imbalance Minimum";
        Default_StockImbalanceMinimum.SetFloat(5000);

        Default_FuturesBoldSize.Name= "Default Futures Bold Size";
        Default_FuturesBoldSize.SetFloat(500);
        Default_FuturesMultiplier.Name= "Default Futures Multiplier";
        Default_FuturesMultiplier.SetCustomInputStrings("0;1;2;3");
        Default_FuturesImbalanceMinimum.Name= "Default Futures Imbalance Minimum";
        Default_FuturesImbalanceMinimum.SetFloat(25);

        Symbol1.Name= "Symbol1";
        Symbol1.SetString("QQQ_MBO");
        Symbol1_BoldSize.Name= "Symbol1 Bold Size";
        Symbol1_BoldSize.SetFloat(500);
        Symbol1_Multiplier.Name= "Symbol1 Multiplier";
        Symbol1_Multiplier.SetCustomInputStrings("0;1;2;3");
        Symbol1_ImbalanceMinimum.Name= "Symbol1 Imbalance Minimum";
        Symbol1_ImbalanceMinimum.SetFloat(25);

        return;
    }

    // https://www.sierrachart.com/index.php?page=doc/ACSIL_Members_Functions.html#scSecurityType


    int BoldSize, Multiplier, ImbalanceMinimum;
    if (sc.Index == 0) {
        if (sc.Symbol.Left(4) == "AAPL") {
            // NumberBars: input id#9 so zero based idx of 8
            // NumberBarsCalc: input id#31 so zero based idx of 30
            // Multipler: (0=1, 1=0.1, 2=0.01, 3=0.001)
            BoldSize = 5000;
            Multiplier = 2;
            ImbalanceMinimum = 500;
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, BoldSize);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, ImbalanceMinimum);
        }

        else if (sc.Symbol.Left(3) == "AMD") {
            BoldSize = 10000;
            Multiplier = 1;
            ImbalanceMinimum = 500;

            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, BoldSize);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, ImbalanceMinimum);
        }
        else if (sc.Symbol.Left(4) == "NFLX") {
            BoldSize = 5000;
            Multiplier = 2;
            ImbalanceMinimum = 500;
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, BoldSize);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, ImbalanceMinimum);
        }
        else if (sc.Symbol.Left(3) == "xxx") {
            BoldSize = 25000;
            Multiplier = 2;
            ImbalanceMinimum = 5000;
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, BoldSize);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, ImbalanceMinimum);
        }
        else if (sc.Symbol == Symbol1.GetString()) {
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Symbol1_Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Symbol1_Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Symbol1_Multiplier);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, Symbol1_BoldSize);
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, Symbol1_ImbalanceMinimum);
        }

        else {
            if 
	    	(sc.SecurityType() == n_ACSIL::SECURITY_TYPE_STOCK) {
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Default_StockMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Default_StockMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Default_StockMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, Default_StockBoldSize.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, Default_StockImbalanceMinimum.GetInt());
            }

            else if 
            (sc.SecurityType() == n_ACSIL::SECURITY_TYPE_FUTURES) {
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, Default_FuturesMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, Default_FuturesMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, Default_FuturesMultiplier.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, Default_FuturesBoldSize.GetInt());
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, Default_FuturesImbalanceMinimum.GetInt());
            }

        

/* Not necessary stuff commented out from original study below
            // tenths
            else if (
                    false
                    //sc.Symbol.Left(0) == "NQ"
                    ) {
                sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, 1);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, 1);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, 1);
                Multiplier = 10;
            }
            // hundredths
            else if (
                    //sc.Symbol.Left(0) == "ES"
                    //|| 
                    sc.Symbol.Left(0) == "ZB"
                    ) {
                sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, 0);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, 0);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, 0);
                Multiplier = 100;
            }
            // thousandths
            else if (
                    sc.Symbol.Left(0) == "ZN"
                    ) {
                sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, 3);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, 3);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, 3);
                Multiplier = 1000;
            }
            // unchanged
            else {
                sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 8, 0);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc1.GetStudyID(), 30, 0);
                sc.SetChartStudyInputInt(sc.ChartNumber, i_NumBarCalc2.GetStudyID(), 30, 0);
                Multiplier = 1;
            }

            // 81 = bold, so 80 zero idx
            if (sc.Symbol.Left(0) == "ES") BoldSize = 1000;
            else if (sc.Symbol.Left(0) == "NQ") BoldSize = 500;
            else if (sc.Symbol.Left(0) == "CL") BoldSize = 15;
            else if (sc.Symbol.Left(0) == "GC") BoldSize = 30;
            else if (sc.Symbol.Left(0) == "ZB") BoldSize = 1000; // 30yr
            else if (sc.Symbol.Left(0) == "ZN") BoldSize = 5000; // 10yr
            else if (sc.Symbol.Left(0) == "ZF") BoldSize = 1000; // 5yr
            else if (sc.Symbol.Left(0) == "ZT") BoldSize = 900;  // 2yr

            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 80, BoldSize);

            // set the Bid/Ask Min Volume Compare Threshold amount
            sc.SetChartStudyInputInt(sc.ChartNumber, i_TargetChart.GetStudyID(), 94, ImbalanceMinimum);
*/
        }

/* Not necessary stuff commented out from original study below
        draw text explaining the settings in top left corner
        if (sc.SecurityType() == n_ACSIL::SECURITY_TYPE_STOCK) {
            s_UseTool Tool;
            Tool.ChartNumber = sc.ChartNumber;
            Tool.LineNumber = 4122022;
            Tool.DrawingType = DRAWING_STATIONARY_TEXT;
            Tool.UseRelativeVerticalValues = 1;
            Tool.BeginValue = 98;
            Tool.BeginDateTime = 2;
            Tool.AddMethod = UTAM_ADD_OR_ADJUST;
            Tool.LineWidth = 1;
            Tool.TransparencyLevel = 70;
            Tool.Region = sc.GraphRegion;
            Tool.FontSize = 10;
            Tool.FontBold = true;
            Tool.Text.Format("1/%d\n%d", Multiplier, BoldSize);
            Tool.Color = COLOR_YELLOW;
            sc.UseTool(Tool);
        }
*/
    }
}