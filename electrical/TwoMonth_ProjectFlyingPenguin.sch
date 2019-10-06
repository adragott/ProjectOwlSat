EESchema Schematic File Version 4
LIBS:TwoMonth_ProjectFlyingPenguin-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Memory_Flash:AT25SF081-XMHD-X U2
U 1 1 5D93C4F3
P 8900 1500
F 0 "U2" H 9541 1546 50  0000 L CNN
F 1 "AT25SF081-XMHD-X" H 9541 1455 50  0000 L CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 8900 900 50  0001 C CNN
F 3 "https://www.adestotech.com/wp-content/uploads/DS-AT25SF081_045.pdf" H 8900 1500 50  0001 C CNN
	1    8900 1500
	1    0    0    -1  
$EndComp
$Comp
L MS561101BA03-50:MS561101BA03-50 U4
U 1 1 5D93C867
P 5450 2700
F 0 "U4" H 5450 3167 50  0000 C CNN
F 1 "MS561101BA03-50" H 5450 3076 50  0000 C CNN
F 2 "MS561101BA03-50:SON125P500X300X100-8N" H 5450 2700 50  0001 L BNN
F 3 "None" H 5450 2700 50  0001 L BNN
F 4 "SMD-8 TE Connectivity" H 5450 2700 50  0001 L BNN "Field4"
F 5 "TE Connectivity" H 5450 2700 50  0001 L BNN "Field5"
F 6 "Pressure Sensor 1.44V to 3.6V 0.01bar to 1.2bar Absolute 8-Pin QFN T/R" H 5450 2700 50  0001 L BNN "Field6"
F 7 "https://www.te.com/usa-en/product-MS561101BA03-50.html?te_bu=Cor&te_type=disp&te_campaign=seda_glo_cor-seda-global-disp-prtnr-fy19-seda-model-bom-cta_sma-317_1&elqCampaignId=32493" H 5450 2700 50  0001 L BNN "Field7"
F 8 "Unavailable" H 5450 2700 50  0001 L BNN "Field8"
F 9 "MS561101BA03-50" H 5450 2700 50  0001 L BNN "Field9"
F 10 "Compliant" H 5450 2700 50  0001 L BNN "Field10"
F 11 "MS561101BA03-50" H 5450 2700 50  0001 L BNN "Field11"
	1    5450 2700
	1    0    0    -1  
$EndComp
$Comp
L TwoMonth_ProjectFlyingPenguin-rescue:Micro_SD_Card_Det-Connector J3
U 1 1 5D93CA9B
P 1900 4250
F 0 "J3" H 1850 5067 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 1850 4976 50  0000 C CNN
F 2 "Connector_Card:SD_TE_2041021" H 3950 4950 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 1900 4350 50  0001 C CNN
	1    1900 4250
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5D93CDAF
P 850 1150
F 0 "J1" H 905 1617 50  0000 C CNN
F 1 "USB_B_Micro" H 905 1526 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Wuerth_629105150521" H 1000 1100 50  0001 C CNN
F 3 "~" H 1000 1100 50  0001 C CNN
	1    850  1150
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M1
U 1 1 5D93D70E
P 6100 1100
F 0 "M1" H 6432 1165 50  0000 L CNN
F 1 "Elevator_Servo" H 6432 1074 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 6100 910 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6100 910 50  0001 C CNN
	1    6100 1100
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_Servo M2
U 1 1 5D93D792
P 6100 1850
F 0 "M2" H 6432 1915 50  0000 L CNN
F 1 "Fin_Servo" H 6432 1824 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 6100 1660 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 6100 1660 50  0001 C CNN
	1    6100 1850
	1    0    0    -1  
$EndComp
$Comp
L TwoMonth_ProjectFlyingPenguin-rescue:Conn_ARM_JTAG_SWD_10-Connector J2
U 1 1 5D93DF61
P 4700 4550
F 0 "J2" H 4260 4596 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 4260 4505 50  0000 R CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 4750 4000 50  0001 L TNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.faqs/attached/13634/cortex_debug_connectors.pdf" V 4350 3300 50  0001 C CNN
	1    4700 4550
	1    0    0    -1  
$EndComp
Text Label 10050 4550 0    50   ~ 0
USB_D-
Text Label 10050 4450 0    50   ~ 0
USB_D+
Text Label 2550 1500 0    50   ~ 0
USB_D-
Text Label 2550 1400 0    50   ~ 0
USB_D+
$Comp
L Connector:Barrel_Jack_Switch J?
U 1 1 5D9C9A5E
P 900 6000
F 0 "J?" H 957 6317 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 957 6226 50  0000 C CNN
F 2 "" H 950 5960 50  0001 C CNN
F 3 "~" H 950 5960 50  0001 C CNN
	1    900  6000
	1    0    0    -1  
$EndComp
$Comp
L dk_Transistors-FETs-MOSFETs-Single:FQP27P06 Q?
U 1 1 5D9D840F
P 3050 6800
F 0 "Q?" V 3300 6800 60  0000 C CNN
F 1 "PFETDefaultA" V 3200 6800 60  0000 C CNN
F 2 "digikey-footprints:TO-220-3" H 3250 7000 60  0001 L CNN
F 3 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 3250 7100 60  0001 L CNN
F 4 "FQP27P06-ND" H 3250 7200 60  0001 L CNN "Digi-Key_PN"
F 5 "FQP27P06" H 3250 7300 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 3250 7400 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 3250 7500 60  0001 L CNN "Family"
F 8 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 3250 7600 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/on-semiconductor/FQP27P06/FQP27P06-ND/965349" H 3250 7700 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 60V 27A TO-220" H 3250 7800 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 3250 7900 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3250 8000 60  0001 L CNN "Status"
	1    3050 6800
	0    -1   -1   0   
$EndComp
$Comp
L dk_Transistors-FETs-MOSFETs-Single:FQP27P06 Q?
U 1 1 5D9DD535
P 4000 5900
F 0 "Q?" V 4200 5900 60  0000 C CNN
F 1 "PFETAltB" V 4100 5900 60  0000 C CNN
F 2 "digikey-footprints:TO-220-3" H 4200 6100 60  0001 L CNN
F 3 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 4200 6200 60  0001 L CNN
F 4 "FQP27P06-ND" H 4200 6300 60  0001 L CNN "Digi-Key_PN"
F 5 "FQP27P06" H 4200 6400 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4200 6500 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 4200 6600 60  0001 L CNN "Family"
F 8 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 4200 6700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/on-semiconductor/FQP27P06/FQP27P06-ND/965349" H 4200 6800 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 60V 27A TO-220" H 4200 6900 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 4200 7000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4200 7100 60  0001 L CNN "Status"
	1    4000 5900
	0    1    -1   0   
$EndComp
$Comp
L dk_Transistors-FETs-MOSFETs-Single:FQP27P06 Q?
U 1 1 5D9DDD10
P 3100 5900
F 0 "Q?" V 3300 5900 60  0000 C CNN
F 1 "PFETAltA" V 3200 5900 60  0000 C CNN
F 2 "digikey-footprints:TO-220-3" H 3300 6100 60  0001 L CNN
F 3 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 3300 6200 60  0001 L CNN
F 4 "FQP27P06-ND" H 3300 6300 60  0001 L CNN "Digi-Key_PN"
F 5 "FQP27P06" H 3300 6400 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 3300 6500 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 3300 6600 60  0001 L CNN "Family"
F 8 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 3300 6700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/on-semiconductor/FQP27P06/FQP27P06-ND/965349" H 3300 6800 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 60V 27A TO-220" H 3300 6900 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 3300 7000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3300 7100 60  0001 L CNN "Status"
	1    3100 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1200 6000 1200 6100
Connection ~ 1200 6100
$Comp
L Regulator_Linear:LM7805_TO220 U?
U 1 1 5D9E58F2
P 2000 5900
F 0 "U?" H 2000 6142 50  0000 C CNN
F 1 "LM2940_TO220" H 2000 6051 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2000 6125 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 2000 5850 50  0001 C CNN
	1    2000 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 6200 1200 6100
$Comp
L power:GND #PWR?
U 1 1 5D9ED297
P 1800 6500
F 0 "#PWR?" H 1800 6250 50  0001 C CNN
F 1 "GND" H 1805 6327 50  0000 C CNN
F 2 "" H 1800 6500 50  0001 C CNN
F 3 "" H 1800 6500 50  0001 C CNN
	1    1800 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 6200 1800 6200
Connection ~ 1800 6200
Wire Wire Line
	1800 6200 1800 6500
Wire Wire Line
	1700 5900 1350 5900
Wire Wire Line
	2300 5900 2350 5900
Wire Wire Line
	1200 6200 1350 6200
$Comp
L Device:C_Small C?
U 1 1 5D9F39B3
P 1350 6000
F 0 "C?" H 1442 6046 50  0000 L CNN
F 1 "0.47uF" H 1442 5955 50  0000 L CNN
F 2 "" H 1350 6000 50  0001 C CNN
F 3 "~" H 1350 6000 50  0001 C CNN
	1    1350 6000
	1    0    0    -1  
$EndComp
Connection ~ 1350 5900
Wire Wire Line
	1350 5900 1200 5900
Wire Wire Line
	1350 6100 1350 6200
Connection ~ 1350 6200
Wire Wire Line
	1350 6200 1800 6200
$Comp
L Device:C_Small C?
U 1 1 5D9F46D7
P 2350 6050
F 0 "C?" H 2442 6096 50  0000 L CNN
F 1 "22uF" H 2442 6005 50  0000 L CNN
F 2 "" H 2350 6050 50  0001 C CNN
F 3 "~" H 2350 6050 50  0001 C CNN
	1    2350 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 5900 2350 5950
Connection ~ 2350 5900
Wire Wire Line
	2350 6150 2350 6200
Wire Wire Line
	2350 6200 2000 6200
Connection ~ 2000 6200
$Comp
L Device:R_Small R?
U 1 1 5D9F5892
P 2700 6050
F 0 "R?" H 2759 6096 50  0000 L CNN
F 1 "200K" H 2759 6005 50  0000 L CNN
F 2 "" H 2700 6050 50  0001 C CNN
F 3 "~" H 2700 6050 50  0001 C CNN
	1    2700 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 5900 3500 5900
$Comp
L dk_TVS-Diodes:PRTR5V0U2X_215 D?
U 1 1 5D9FFAC4
P 2100 2100
F 0 "D?" V 2153 1812 60  0000 R CNN
F 1 "PRTR5V0U2X_215" V 2047 1812 60  0000 R CNN
F 2 "digikey-footprints:TO-253-4" H 2300 2300 60  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PRTR5V0U2X.pdf" H 2300 2400 60  0001 L CNN
F 4 "1727-3884-1-ND" H 2300 2500 60  0001 L CNN "Digi-Key_PN"
F 5 "PRTR5V0U2X,215" H 2300 2600 60  0001 L CNN "MPN"
F 6 "Circuit Protection" H 2300 2700 60  0001 L CNN "Category"
F 7 "TVS - Diodes" H 2300 2800 60  0001 L CNN "Family"
F 8 "https://assets.nexperia.com/documents/data-sheet/PRTR5V0U2X.pdf" H 2300 2900 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/nexperia-usa-inc/PRTR5V0U2X,215/1727-3884-1-ND/1589981" H 2300 3000 60  0001 L CNN "DK_Detail_Page"
F 10 "TVS DIODE 5.5V SOT143B" H 2300 3100 60  0001 L CNN "Description"
F 11 "Nexperia USA Inc." H 2300 3200 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2300 3300 60  0001 L CNN "Status"
	1    2100 2100
	0    -1   -1   0   
$EndComp
$Comp
L Sensor_Motion:BNO055 U3
U 1 1 5D93C5B0
P 3550 2900
F 0 "U3" H 3550 3778 50  0000 C CNN
F 1 "BNO055" H 3550 3687 50  0000 C CNN
F 2 "Package_LGA:LGA-28_5.2x3.8mm_P0.5mm" H 3800 2250 50  0001 L CNN
F 3 "https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST_BNO055_DS000_14.pdf" H 3550 3100 50  0001 C CNN
	1    3550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 4450 9950 4450
Wire Wire Line
	9950 4550 10050 4550
Wire Wire Line
	1150 950  1900 950 
Wire Wire Line
	1900 2600 1900 2750
$Comp
L power:GND #PWR?
U 1 1 5DA0C487
P 1900 2750
F 0 "#PWR?" H 1900 2500 50  0001 C CNN
F 1 "GND" H 1905 2577 50  0000 C CNN
F 2 "" H 1900 2750 50  0001 C CNN
F 3 "" H 1900 2750 50  0001 C CNN
	1    1900 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 2600 2300 2700
Wire Wire Line
	2300 2700 2450 2700
Wire Wire Line
	2450 2700 2450 1400
Wire Wire Line
	2450 1400 2550 1400
Wire Wire Line
	2300 1500 2300 1600
Wire Wire Line
	2300 1500 2550 1500
$Comp
L Device:C_Small C?
U 1 1 5DA10983
P 2050 900
F 0 "C?" H 2142 946 50  0000 L CNN
F 1 "1nF" H 2142 855 50  0000 L CNN
F 2 "" H 2050 900 50  0001 C CNN
F 3 "~" H 2050 900 50  0001 C CNN
	1    2050 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 950  1900 1600
Wire Wire Line
	1150 1150 1750 1150
Wire Wire Line
	1750 1150 1750 1400
Wire Wire Line
	1750 1400 2450 1400
Connection ~ 2450 1400
Wire Wire Line
	1150 1250 1650 1250
Wire Wire Line
	1650 1250 1650 1500
Wire Wire Line
	1650 1500 2300 1500
Connection ~ 2300 1500
Wire Wire Line
	2050 1000 2050 1100
$Comp
L power:GND #PWR?
U 1 1 5DA15A43
P 2050 1100
F 0 "#PWR?" H 2050 850 50  0001 C CNN
F 1 "GND" H 2055 927 50  0000 C CNN
F 2 "" H 2050 1100 50  0001 C CNN
F 3 "" H 2050 1100 50  0001 C CNN
	1    2050 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 950  1900 800 
Wire Wire Line
	1900 800  2050 800 
Connection ~ 1900 950 
Connection ~ 2050 800 
Wire Wire Line
	2050 800  2300 800 
Wire Wire Line
	2500 800  2750 800 
$Comp
L Device:C_Small C?
U 1 1 5DA17CAE
P 2750 900
F 0 "C?" H 2842 946 50  0000 L CNN
F 1 "1nF" H 2842 855 50  0000 L CNN
F 2 "" H 2750 900 50  0001 C CNN
F 3 "~" H 2750 900 50  0001 C CNN
	1    2750 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1000 2750 1100
$Comp
L power:GND #PWR?
U 1 1 5DA19130
P 2750 1100
F 0 "#PWR?" H 2750 850 50  0001 C CNN
F 1 "GND" H 2755 927 50  0000 C CNN
F 2 "" H 2750 1100 50  0001 C CNN
F 3 "" H 2750 1100 50  0001 C CNN
	1    2750 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 800  3100 800 
Connection ~ 2750 800 
Text Label 3100 800  0    50   ~ 0
USB_5V+
NoConn ~ 1150 1350
Wire Wire Line
	750  1550 850  1550
$Comp
L power:GND #PWR?
U 1 1 5DA1D650
P 850 1550
F 0 "#PWR?" H 850 1300 50  0001 C CNN
F 1 "GND" H 855 1377 50  0000 C CNN
F 2 "" H 850 1550 50  0001 C CNN
F 3 "" H 850 1550 50  0001 C CNN
	1    850  1550
	1    0    0    -1  
$EndComp
Connection ~ 850  1550
Connection ~ 9650 5650
Wire Wire Line
	9650 5650 9750 5650
Connection ~ 9550 5650
Wire Wire Line
	9550 5650 9650 5650
Wire Wire Line
	9450 5650 9550 5650
$Comp
L dk_Embedded-Microcontrollers:ATSAMD21G18A-AUT U1
U 1 1 5D93B0C8
P 9450 4250
F 0 "U1" H 8950 2950 60  0000 C CNN
F 1 "ATSAMD21G18A-AUT" H 8900 2800 60  0000 C CNN
F 2 "digikey-footprints:TQFP-48_7x7mm" H 9650 4450 60  0001 L CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en605782" H 9650 4550 60  0001 L CNN
F 4 "ATSAMD21G18A-AUTCT-ND" H 9650 4650 60  0001 L CNN "Digi-Key_PN"
F 5 "ATSAMD21G18A-AUT" H 9650 4750 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9650 4850 60  0001 L CNN "Category"
F 7 "Embedded - Microcontrollers" H 9650 4950 60  0001 L CNN "Family"
F 8 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en605782" H 9650 5050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/microchip-technology/ATSAMD21G18A-AUT/ATSAMD21G18A-AUTCT-ND/4878879" H 9650 5150 60  0001 L CNN "DK_Detail_Page"
F 10 "IC MCU 32BIT 256KB FLASH 48TQFP" H 9650 5250 60  0001 L CNN "Description"
F 11 "Microchip Technology" H 9650 5350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9650 5450 60  0001 L CNN "Status"
	1    9450 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5650 9450 5700
Connection ~ 9450 5650
$Comp
L power:GND #PWR?
U 1 1 5DA23557
P 9450 5700
F 0 "#PWR?" H 9450 5450 50  0001 C CNN
F 1 "GND" H 9455 5527 50  0000 C CNN
F 2 "" H 9450 5700 50  0001 C CNN
F 3 "" H 9450 5700 50  0001 C CNN
	1    9450 5700
	1    0    0    -1  
$EndComp
Text Label 2250 6800 2    50   ~ 0
USB_5V+
Wire Wire Line
	3150 7100 3500 7100
Connection ~ 3500 5900
Wire Wire Line
	3500 5900 3800 5900
$Comp
L Device:R_Small R?
U 1 1 5DA2DDF8
P 3500 7200
F 0 "R?" H 3600 7150 50  0000 L CNN
F 1 "100K" H 3600 7050 50  0000 L CNN
F 2 "" H 3500 7200 50  0001 C CNN
F 3 "~" H 3500 7200 50  0001 C CNN
	1    3500 7200
	1    0    0    -1  
$EndComp
Connection ~ 3500 7100
Wire Wire Line
	3500 7300 3500 7350
$Comp
L power:GND #PWR?
U 1 1 5DA31D3D
P 3500 7350
F 0 "#PWR?" H 3500 7100 50  0001 C CNN
F 1 "GND" H 3505 7177 50  0000 C CNN
F 2 "" H 3500 7350 50  0001 C CNN
F 3 "" H 3500 7350 50  0001 C CNN
	1    3500 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 6800 3750 6800
Wire Wire Line
	2250 6800 2300 6800
Wire Wire Line
	2300 6800 2300 7050
Connection ~ 2300 6800
Wire Wire Line
	2300 6800 2700 6800
$Comp
L Device:R_Small R?
U 1 1 5DA35BA2
P 2300 7150
F 0 "R?" H 2350 7150 50  0000 L CNN
F 1 "200K" H 2350 7050 50  0000 L CNN
F 2 "" H 2300 7150 50  0001 C CNN
F 3 "~" H 2300 7150 50  0001 C CNN
	1    2300 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 7250 2300 7350
$Comp
L power:GND #PWR?
U 1 1 5DA37896
P 2300 7350
F 0 "#PWR?" H 2300 7100 50  0001 C CNN
F 1 "GND" H 2305 7177 50  0000 C CNN
F 2 "" H 2300 7350 50  0001 C CNN
F 3 "" H 2300 7350 50  0001 C CNN
	1    2300 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5900 4500 5900
Wire Wire Line
	4500 5900 4500 6300
Wire Wire Line
	4500 6800 4150 6800
Connection ~ 4500 6300
Wire Wire Line
	4500 6300 4500 6800
$Comp
L Device:Ferrite_Bead_Small FB?
U 1 1 5DA0EFAC
P 2400 800
F 0 "FB?" V 2163 800 50  0000 C CNN
F 1 "470 @ 100Mhz" V 2254 800 50  0000 C CNN
F 2 "" V 2330 800 50  0001 C CNN
F 3 "~" H 2400 800 50  0001 C CNN
	1    2400 800 
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5DA44028
P 5400 6400
F 0 "C?" H 5200 6450 50  0000 L CNN
F 1 "10uF" H 5100 6350 50  0000 L CNN
F 2 "" H 5400 6400 50  0001 C CNN
F 3 "~" H 5400 6400 50  0001 C CNN
	1    5400 6400
	1    0    0    -1  
$EndComp
Connection ~ 5400 6300
Wire Wire Line
	5400 6300 5500 6300
$Comp
L Regulator_Linear:LM7805_TO220 U?
U 1 1 5DA3E4A8
P 5800 6300
F 0 "U?" H 5800 6542 50  0000 C CNN
F 1 "MIC29310" H 5800 6451 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5800 6525 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 5800 6250 50  0001 C CNN
	1    5800 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6500 5400 6600
Wire Wire Line
	5400 6600 5800 6600
$Comp
L power:+3V3 #PWR?
U 1 1 5DA4AAD8
P 6300 6300
F 0 "#PWR?" H 6300 6150 50  0001 C CNN
F 1 "+3V3" V 6315 6428 50  0000 L CNN
F 2 "" H 6300 6300 50  0001 C CNN
F 3 "" H 6300 6300 50  0001 C CNN
	1    6300 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 6300 6150 6300
$Comp
L Device:C_Small C?
U 1 1 5DA4C3D1
P 6150 6400
F 0 "C?" H 6250 6450 50  0000 L CNN
F 1 "10uF" H 6250 6350 50  0000 L CNN
F 2 "" H 6150 6400 50  0001 C CNN
F 3 "~" H 6150 6400 50  0001 C CNN
	1    6150 6400
	1    0    0    -1  
$EndComp
Connection ~ 6150 6300
Wire Wire Line
	6150 6300 6300 6300
Wire Wire Line
	6150 6500 6150 6600
Wire Wire Line
	6150 6600 5800 6600
Connection ~ 5800 6600
Wire Wire Line
	5800 6600 5800 6700
$Comp
L power:GND #PWR?
U 1 1 5DA51467
P 5800 6700
F 0 "#PWR?" H 5800 6450 50  0001 C CNN
F 1 "GND" H 5805 6527 50  0000 C CNN
F 2 "" H 5800 6700 50  0001 C CNN
F 3 "" H 5800 6700 50  0001 C CNN
	1    5800 6700
	1    0    0    -1  
$EndComp
$Sheet
S 500  5550 6200 2100
U 5D9B14E1
F0 "POWER" 50
F1 "POWER.sch" 50
$EndSheet
Wire Wire Line
	4500 6300 5000 6300
Wire Wire Line
	5000 6300 5000 6200
Connection ~ 5000 6300
Wire Wire Line
	5000 6300 5400 6300
$Comp
L power:+5V #PWR?
U 1 1 5DA5AEE8
P 5000 6200
F 0 "#PWR?" H 5000 6050 50  0001 C CNN
F 1 "+5V" H 5015 6373 50  0000 C CNN
F 2 "" H 5000 6200 50  0001 C CNN
F 3 "" H 5000 6200 50  0001 C CNN
	1    5000 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 6200 3200 6400
Wire Wire Line
	3200 6400 2700 6400
Wire Wire Line
	2700 6400 2700 6800
Connection ~ 3200 6200
Connection ~ 2700 6800
Wire Wire Line
	2700 6800 2850 6800
Wire Wire Line
	10200 550  10100 550 
Wire Wire Line
	10200 600  10200 550 
Wire Wire Line
	10100 1350 10100 950 
Wire Wire Line
	10200 1350 10100 1350
Wire Wire Line
	10200 1300 10200 1350
Wire Wire Line
	10200 1050 10200 1100
$Comp
L Device:C_Small C?
U 1 1 5DA742C8
P 10200 1200
F 0 "C?" H 10292 1246 50  0000 L CNN
F 1 "6.8pF" H 10292 1155 50  0000 L CNN
F 2 "" H 10200 1200 50  0001 C CNN
F 3 "~" H 10200 1200 50  0001 C CNN
	1    10200 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DA74078
P 10050 950
F 0 "#PWR?" H 10050 700 50  0001 C CNN
F 1 "GND" V 10055 822 50  0000 R CNN
F 2 "" H 10050 950 50  0001 C CNN
F 3 "" H 10050 950 50  0001 C CNN
	1    10050 950 
	0    1    1    0   
$EndComp
Connection ~ 10100 950 
Wire Wire Line
	10100 950  10050 950 
Wire Wire Line
	10100 550  10100 950 
$Comp
L Device:C_Small C?
U 1 1 5DA6F2C7
P 10200 700
F 0 "C?" H 10292 746 50  0000 L CNN
F 1 "6.8pF" H 10292 655 50  0000 L CNN
F 2 "" H 10200 700 50  0001 C CNN
F 3 "~" H 10200 700 50  0001 C CNN
	1    10200 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 850  10200 800 
$Comp
L Device:Crystal_GND2_Small Y?
U 1 1 5DA6B7B8
P 10200 950
F 0 "Y?" V 10154 1038 50  0000 L CNN
F 1 "32.768kHz" V 10150 1150 50  0000 L CNN
F 2 "" H 10200 950 50  0001 C CNN
F 3 "~" H 10200 950 50  0001 C CNN
	1    10200 950 
	0    1    1    0   
$EndComp
Connection ~ 10200 800 
Wire Wire Line
	10200 1050 10550 1050
Connection ~ 10200 1050
Wire Wire Line
	10200 800  10550 800 
Text Label 10550 800  0    50   ~ 0
XIN32
Text Label 10550 1050 0    50   ~ 0
XOUT32
Wire Wire Line
	8950 3150 8900 3150
Wire Wire Line
	8950 3250 8900 3250
Text Label 8900 3150 2    50   ~ 0
XIN32
Text Label 8900 3250 2    50   ~ 0
XOUT32
$Sheet
S 6950 2150 4100 4200
U 5DA9EF01
F0 "BRAIN" 50
F1 "BRAIN.sch" 50
$EndSheet
$Comp
L dk_Transistors-FETs-MOSFETs-Single:FQP27P06 Q?
U 1 1 5D9DC7E3
P 3950 6800
F 0 "Q?" V 4200 6800 60  0000 C CNN
F 1 "PFETDefaultB" V 4100 6800 60  0000 C CNN
F 2 "digikey-footprints:TO-220-3" H 4150 7000 60  0001 L CNN
F 3 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 4150 7100 60  0001 L CNN
F 4 "FQP27P06-ND" H 4150 7200 60  0001 L CNN "Digi-Key_PN"
F 5 "FQP27P06" H 4150 7300 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 4150 7400 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 4150 7500 60  0001 L CNN "Family"
F 8 "https://www.onsemi.com/pub/Collateral/FQP27P06-D.PDF" H 4150 7600 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/on-semiconductor/FQP27P06/FQP27P06-ND/965349" H 4150 7700 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 60V 27A TO-220" H 4150 7800 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 4150 7900 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4150 8000 60  0001 L CNN "Status"
	1    3950 6800
	0    1    -1   0   
$EndComp
Wire Wire Line
	3500 5900 3500 7100
Wire Wire Line
	3850 7100 3500 7100
Wire Wire Line
	3200 6200 3900 6200
Wire Wire Line
	2350 5900 2700 5900
Wire Wire Line
	2700 5900 2700 5950
Connection ~ 2700 5900
Wire Wire Line
	2700 5900 2900 5900
Wire Wire Line
	2700 6150 2700 6200
Wire Wire Line
	2700 6200 2350 6200
Connection ~ 2350 6200
$EndSCHEMATC
