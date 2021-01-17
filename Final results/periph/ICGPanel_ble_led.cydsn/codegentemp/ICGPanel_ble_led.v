// ======================================================================
// ICGPanel_ble_led.v generated from TopDesign.cysch
// 01/16/2021 at 23:07
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 2
`define CYDEV_CHIP_MEMBER_USED 27
`define CYDEV_CHIP_REVISION_USED 0
// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// BLE_v3_66(AutopopulateWhitelist=true, EnableExternalPAcontrol=false, EnableExternalPrepWriteBuff=false, EnableL2capLogicalChannels=true, EnableLinkLayerPrivacy=false, GapConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<CyGapConfiguration xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">\r\n  <DevAddress>00A050000000</DevAddress>\r\n  <SiliconGeneratedAddress>true</SiliconGeneratedAddress>\r\n  <MtuSize>23</MtuSize>\r\n  <MaxTxPayloadSize>27</MaxTxPayloadSize>\r\n  <MaxRxPayloadSize>27</MaxRxPayloadSize>\r\n  <TxPowerLevel>0</TxPowerLevel>\r\n  <TxPowerLevelConnection>0</TxPowerLevelConnection>\r\n  <TxPowerLevelAdvScan>0</TxPowerLevelAdvScan>\r\n  <SecurityConfig>\r\n    <SecurityMode>SECURITY_MODE_1</SecurityMode>\r\n    <SecurityLevel>NO_SECURITY</SecurityLevel>\r\n    <StrictPairing>false</StrictPairing>\r\n    <KeypressNotifications>false</KeypressNotifications>\r\n    <IOCapability>NO_INPUT_NO_OUTPUT</IOCapability>\r\n    <PairingMethod>JUST_WORKS</PairingMethod>\r\n    <Bonding>NO_BOND</Bonding>\r\n    <MaxBondedDevices>4</MaxBondedDevices>\r\n    <AutoPopWhitelistBondedDev>true</AutoPopWhitelistBondedDev>\r\n    <MaxWhitelistSize>8</MaxWhitelistSize>\r\n    <EnableLinkLayerPrivacy>false</EnableLinkLayerPrivacy>\r\n    <MaxResolvableDevices>8</MaxResolvableDevices>\r\n    <EncryptionKeySize>16</EncryptionKeySize>\r\n  </SecurityConfig>\r\n  <AdvertisementConfig>\r\n    <AdvScanMode>FAST_CONNECTION</AdvScanMode>\r\n    <AdvFastScanInterval>\r\n      <Minimum>20</Minimum>\r\n      <Maximum>30</Maximum>\r\n    </AdvFastScanInterval>\r\n    <AdvReducedScanInterval>\r\n      <Minimum>1000</Minimum>\r\n      <Maximum>10240</Maximum>\r\n    </AdvReducedScanInterval>\r\n    <AdvDiscoveryMode>GENERAL</AdvDiscoveryMode>\r\n    <AdvType>CONNECTABLE_UNDIRECTED</AdvType>\r\n    <AdvFilterPolicy>SCAN_REQUEST_ANY_CONNECT_REQUEST_ANY</AdvFilterPolicy>\r\n    <AdvChannelMap>ALL</AdvChannelMap>\r\n    <AdvFastTimeout>30</AdvFastTimeout>\r\n    <AdvReducedTimeout>150</AdvReducedTimeout>\r\n    <EnableReducedAdvertising>false</EnableReducedAdvertising>\r\n    <ConnectionInterval>\r\n      <Minimum>7.5</Minimum>\r\n      <Maximum>50</Maximum>\r\n    </ConnectionInterval>\r\n    <ConnectionSlaveLatency>0</ConnectionSlaveLatency>\r\n    <ConnectionTimeout>10000</ConnectionTimeout>\r\n  </AdvertisementConfig>\r\n  <ScanConfig>\r\n    <ScanFastWindow>30</ScanFastWindow>\r\n    <ScanFastInterval>30</ScanFastInterval>\r\n    <ScanTimeout>30</ScanTimeout>\r\n    <ScanReducedWindow>1125</ScanReducedWindow>\r\n    <ScanReducedInterval>1280</ScanReducedInterval>\r\n    <ScanReducedTimeout>150</ScanReducedTimeout>\r\n    <EnableReducedScan>true</EnableReducedScan>\r\n    <ScanDiscoveryMode>GENERAL</ScanDiscoveryMode>\r\n    <ScanningState>ACTIVE</ScanningState>\r\n    <ScanFilterPolicy>ACCEPT_ALL_ADV_PACKETS</ScanFilterPolicy>\r\n    <DuplicateFiltering>false</DuplicateFiltering>\r\n    <ConnectionInterval>\r\n      <Minimum>7.5</Minimum>\r\n      <Maximum>50</Maximum>\r\n    </ConnectionInterval>\r\n    <ConnectionSlaveLatency>0</ConnectionSlaveLatency>\r\n    <ConnectionTimeout>10000</ConnectionTimeout>\r\n  </ScanConfig>\r\n  <AdvertisementPacket>\r\n    <PacketType>ADVERTISEMENT</PacketType>\r\n    <Items>\r\n      <CyADStructure>\r\n        <ADType>1</ADType>\r\n        <ADData>06</ADData>\r\n      </CyADStructure>\r\n      <CyADStructure>\r\n        <ADType>9</ADType>\r\n        <ADData>42:49:6B:65:53:74:61:74:65:73</ADData>\r\n      </CyADStructure>\r\n    </Items>\r\n    <IncludedServicesServiceUuid />\r\n    <IncludedServicesServiceSolicitation />\r\n    <IncludedServicesServiceData />\r\n  </AdvertisementPacket>\r\n  <ScanResponsePacket>\r\n    <PacketType>SCAN_RESPONSE</PacketType>\r\n    <Items>\r\n      <CyADStructure>\r\n        <ADType>3</ADType>\r\n        <ADData>46:7A</ADData>\r\n      </CyADStructure>\r\n    </Items>\r\n    <IncludedServicesServiceUuid>\r\n      <int>12</int>\r\n    </IncludedServicesServiceUuid>\r\n    <IncludedServicesServiceSolicitation />\r\n    <IncludedServicesServiceData />\r\n  </ScanResponsePacket>\r\n</CyGapConfiguration>, HalBaudRate=115200, HalCtsEnable=true, HalCtsPolarity=0, HalRtsEnable=true, HalRtsPolarity=0, HalRtsTriggerLevel=4, HciMode=0, ImportFilePath=, KeypressNotifications=false, L2capMpsSize=23, L2capMtuSize=23, L2capNumChannels=1, L2capNumPsm=1, LLMaxRxPayloadSize=27, LLMaxTxPayloadSize=27, MaxAttrNoOfBuffer=1, MaxBondedDevices=4, MaxResolvableDevices=8, MaxWhitelistSize=8, Mode=0, ProfileConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<Profile xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" ID="1" DisplayName="Custom" Name="Custom" Type="org.bluetooth.profile.custom">\r\n  <CyProfileRole ID="2" DisplayName="Server" Name="Server">\r\n    <CyService ID="3" DisplayName="Generic Access" Name="Generic Access" Type="org.bluetooth.service.generic_access" UUID="1800">\r\n      <CyCharacteristic ID="4" DisplayName="Device Name" Name="Device Name" Type="org.bluetooth.characteristic.gap.device_name" UUID="2A00">\r\n        <Field Name="Name">\r\n          <DataFormat>utf8s</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>BIkeStates</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="5" DisplayName="Appearance" Name="Appearance" Type="org.bluetooth.characteristic.gap.appearance" UUID="2A01">\r\n        <Field Name="Category">\r\n          <DataFormat>16bit</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="6" DisplayName="Peripheral Preferred Connection Parameters" Name="Peripheral Preferred Connection Parameters" Type="org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters" UUID="2A04">\r\n        <Field Name="Minimum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0006</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Maximum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0028</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Slave Latency">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>0</Minimum>\r\n            <Maximum>1000</Maximum>\r\n          </Range>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Connection Supervision Timeout Multiplier">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>10</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x03E8</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="7" DisplayName="Central Address Resolution" Name="Central Address Resolution" Type="org.bluetooth.characteristic.gap.central_address_resolution" UUID="2AA6">\r\n        <Field Name="Central Address Resolution Support">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="8" DisplayName="Resolvable Private Address Only" Name="Resolvable Private Address Only" Type="org.bluetooth.characteristic.gap.resolvable_private_address_only" UUID="2AC9">\r\n        <Field Name="Resolvable Private Address Only">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="9" DisplayName="Generic Attribute" Name="Generic Attribute" Type="org.bluetooth.service.generic_attribute" UUID="1801">\r\n      <CyCharacteristic ID="10" DisplayName="Service Changed" Name="Service Changed" Type="org.bluetooth.characteristic.gatt.service_changed" UUID="2A05">\r\n        <CyDescriptor ID="11" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="true" />\r\n            <Property Type="WRITE" Present="true" Mandatory="true" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Start of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="End of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="INDICATE" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>NONE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="12" DisplayName="BikeStatus" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="7A46">\r\n      <CyCharacteristic ID="13" DisplayName="BikeStatusCharacteristic" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="AEC7">\r\n        <CyDescriptor ID="15" DisplayName="Characteristic User Description" Name="Characteristic User Description" Type="org.bluetooth.descriptor.gatt.characteristic_user_description" UUID="2901">\r\n          <Field Name="User Description">\r\n            <DataFormat>utf8s</DataFormat>\r\n            <ByteLength>10</ByteLength>\r\n            <ValueType>BASIC</ValueType>\r\n            <GeneralValue>BikeStatus</GeneralValue>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="false" />\r\n            <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          </Properties>\r\n          <Permission />\r\n        </CyDescriptor>\r\n        <Field Name="Status">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>READ_WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <ProfileRoleIndex>0</ProfileRoleIndex>\r\n    <RoleType>SERVER</RoleType>\r\n  </CyProfileRole>\r\n  <GapRole>PERIPHERAL</GapRole>\r\n</Profile>, SharingMode=0, StackMode=3, StrictPairing=false, UseDeepSleep=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMMENT=, CY_COMPONENT_NAME=BLE_v3_66, CY_CONFIG_TITLE=CyBle, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=BLE_v3_66.pdf, CY_FITTER_NAME=CyBle, CY_INSTANCE_SHORT_NAME=CyBle, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=66, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=CyBle, )
module BLE_v3_66_0 (
    clk,
    pa_en);
    output      clk;
    output      pa_en;


          wire  Net_89;
          wire  Net_107;
          wire  Net_106;
          wire  Net_105;
          wire  Net_93;
          wire  Net_92;
          wire  Net_91;
          wire  Net_101;
          wire  Net_104;
          wire  Net_102;
          wire  Net_103;
          wire  Net_90;
          wire  Net_100;
          wire  Net_99;
          wire  Net_98;
          wire  Net_97;
          wire  Net_96;
          wire  Net_95;
          wire  Net_94;
          wire  Net_88;
          wire  Net_70;
          wire  Net_15;
          wire  Net_14;
          wire  Net_53;
          wire  Net_60;
          wire  Net_55;

    cy_m0s8_ble_v1_0 cy_m0s8_ble (
        .interrupt(Net_15),
        .rf_ext_pa_en(pa_en));


	cy_isr_v1_0
		#(.int_type(2'b10))
		bless_isr
		 (.int_signal(Net_15));



	cy_clock_v1_0
		#(.id("6812bbf4-5fba-4ea1-a109-5de83f7b3b3f/5ae6fa4d-f41a-4a35-8821-7ce70389cb0c"),
		  .source_clock_id("9A908CA6-5BB3-4db0-B098-959E5D90882B"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(0))
		LFCLK
		 (.clock_out(Net_53));



    assign clk = Net_55 | Net_53;

    assign Net_55 = 1'h0;



endmodule

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: demux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\demux_v1_10\demux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\demux_v1_10\demux_v1_10.v"
`endif

// Component: B_WS2811_v1_3
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\gala_\Documents\cycling_glove\WS281xLib.cylib\B_WS2811_v1_3"
`include "C:\Users\gala_\Documents\cycling_glove\WS281xLib.cylib\B_WS2811_v1_3\B_WS2811_v1_3.v"
`else
`define CY_BLK_DIR "C:\Users\gala_\Documents\cycling_glove\WS281xLib.cylib\B_WS2811_v1_3"
`include "C:\Users\gala_\Documents\cycling_glove\WS281xLib.cylib\B_WS2811_v1_3\B_WS2811_v1_3.v"
`endif

// StripLights_v3_0(Channels=1, ClockSpeedKhz=800, Coord_Wrap=0, Display_Memory=0, Flip_X_Coord=false, Flip_Y_Coord=false, Gamma_Correction=false, Grid_16x16_Columns=2, Grid_16x16_Rows=1, LED_Config=0, LedChannels=1, LEDs_per_Strip=68, Speed=1, String_Wrap_Length=10, Swap_X_Y=false, Transfer_Method=1, WS281x_Type=1, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMMENT=, CY_COMPONENT_NAME=StripLights_v3_0, CY_CONFIG_TITLE=StripLights, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=StripLights, CY_INSTANCE_SHORT_NAME=StripLights, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=StripLights, )
module StripLights_v3_0_1 (
    rdy,
    S0,
    S1,
    S10,
    S11,
    S12,
    S13,
    S14,
    S15,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8,
    S9);
    output      rdy;
    output      S0;
    output      S1;
    output      S10;
    output      S11;
    output      S12;
    output      S13;
    output      S14;
    output      S15;
    output      S2;
    output      S3;
    output      S4;
    output      S5;
    output      S6;
    output      S7;
    output      S8;
    output      S9;


          wire [3:0] saddr;
          wire  Net_26;
          wire  Net_24;
          wire  Net_23;
          wire  Net_22;
          wire  Net_21;
          wire  Net_25;
          wire  Net_15;
          wire  Net_8;
          wire  Net_64;
          wire  Net_18;
          wire  Net_159;
          wire  Net_7;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_7));


	cy_isr_v1_0
		#(.int_type(2'b00))
		fisr
		 (.int_signal(Net_159));


    // -- De Mux start --
    if (1)
    begin : demux_1
        reg  tmp__demux_1_0_reg;
        reg  tmp__demux_1_1_reg;
        reg  tmp__demux_1_2_reg;
        reg  tmp__demux_1_3_reg;
        reg  tmp__demux_1_4_reg;
        reg  tmp__demux_1_5_reg;
        reg  tmp__demux_1_6_reg;
        reg  tmp__demux_1_7_reg;
        reg  tmp__demux_1_8_reg;
        reg  tmp__demux_1_9_reg;
        reg  tmp__demux_1_10_reg;
        reg  tmp__demux_1_11_reg;
        reg  tmp__demux_1_12_reg;
        reg  tmp__demux_1_13_reg;
        reg  tmp__demux_1_14_reg;
        reg  tmp__demux_1_15_reg;
        always @(Net_64 or saddr)
        begin
            case (saddr[3:0])
                4'b0000:
                begin
                    tmp__demux_1_0_reg = Net_64;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0001:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = Net_64;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0010:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = Net_64;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0011:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = Net_64;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0100:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = Net_64;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0101:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = Net_64;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0110:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = Net_64;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b0111:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = Net_64;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1000:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = Net_64;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1001:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = Net_64;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1010:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = Net_64;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1011:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = Net_64;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1100:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = Net_64;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1101:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = Net_64;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1110:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = Net_64;
                    tmp__demux_1_15_reg = 1'b0;
                end
                4'b1111:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = 1'b0;
                    tmp__demux_1_2_reg = 1'b0;
                    tmp__demux_1_3_reg = 1'b0;
                    tmp__demux_1_4_reg = 1'b0;
                    tmp__demux_1_5_reg = 1'b0;
                    tmp__demux_1_6_reg = 1'b0;
                    tmp__demux_1_7_reg = 1'b0;
                    tmp__demux_1_8_reg = 1'b0;
                    tmp__demux_1_9_reg = 1'b0;
                    tmp__demux_1_10_reg = 1'b0;
                    tmp__demux_1_11_reg = 1'b0;
                    tmp__demux_1_12_reg = 1'b0;
                    tmp__demux_1_13_reg = 1'b0;
                    tmp__demux_1_14_reg = 1'b0;
                    tmp__demux_1_15_reg = Net_64;
                end
            endcase
        end
        assign S0 = tmp__demux_1_0_reg;
        assign S1 = tmp__demux_1_1_reg;
        assign S2 = tmp__demux_1_2_reg;
        assign S3 = tmp__demux_1_3_reg;
        assign S4 = tmp__demux_1_4_reg;
        assign S5 = tmp__demux_1_5_reg;
        assign S6 = tmp__demux_1_6_reg;
        assign S7 = tmp__demux_1_7_reg;
        assign S8 = tmp__demux_1_8_reg;
        assign S9 = tmp__demux_1_9_reg;
        assign S10 = tmp__demux_1_10_reg;
        assign S11 = tmp__demux_1_11_reg;
        assign S12 = tmp__demux_1_12_reg;
        assign S13 = tmp__demux_1_13_reg;
        assign S14 = tmp__demux_1_14_reg;
        assign S15 = tmp__demux_1_15_reg;
    end
    // -- De Mux end --

    B_WS2811_v1_3 B_WS2811 (
        .cirq(rdy),
        .clk(Net_18),
        .cntl(Net_8),
        .firq(Net_159),
        .reset(Net_7),
        .sout(Net_64));


	cy_isr_v1_0
		#(.int_type(2'b00))
		cisr
		 (.int_signal(rdy));



	cy_clock_v1_0
		#(.id("44fb0532-dea1-4a77-bfb9-020ab4a9eb65/0a506fc7-6fb5-4469-85ac-443b91c6dcd4"),
		  .source_clock_id("413DE2EF-D9F2-4233-A808-DFAF137FD877"),
		  .divisor(2),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_18));


    CyControlReg_v1_80 StringSel (
        .clock(1'b0),
        .control_0(saddr[0]),
        .control_1(saddr[1]),
        .control_2(saddr[2]),
        .control_3(saddr[3]),
        .control_4(Net_21),
        .control_5(Net_22),
        .control_6(Net_23),
        .control_7(Net_24),
        .reset(1'b0));
    defparam StringSel.Bit0Mode = 0;
    defparam StringSel.Bit1Mode = 0;
    defparam StringSel.Bit2Mode = 0;
    defparam StringSel.Bit3Mode = 0;
    defparam StringSel.Bit4Mode = 0;
    defparam StringSel.Bit5Mode = 0;
    defparam StringSel.Bit6Mode = 0;
    defparam StringSel.Bit7Mode = 0;
    defparam StringSel.BitValue = 0;
    defparam StringSel.BusDisplay = 0;
    defparam StringSel.ExtrReset = 0;
    defparam StringSel.NumOutputs = 8;



endmodule

// top
module top ;

          wire  Net_215;
          wire  Net_214;
          wire  Net_213;
          wire  Net_212;
          wire  Net_211;
          wire  Net_210;
          wire  Net_209;
          wire  Net_208;
          wire  Net_207;
          wire  Net_206;
          wire  Net_205;
          wire  Net_204;
          wire  Net_203;
          wire  Net_202;
          wire  Net_201;
          wire  Net_199;
          wire  Net_200;
          wire  Net_190;
          wire  Net_188;
          wire  Net_185;
          wire  Net_191;
          wire  Net_192;
          wire  Net_193;
          wire  Net_189;
          wire  Net_176;
          wire  Net_175;
    electrical  Net_1;
    electrical  Net_22;
    electrical  Net_3;
          wire  Net_179;
          wire  Net_195;
          wire  Net_178;

    BLE_v3_66_0 CyBle (
        .clk(Net_175),
        .pa_en(Net_176));

	wire [0:0] tmpOE__PinRight_net;
	wire [0:0] tmpFB_0__PinRight_net;
	wire [0:0] tmpIO_0__PinRight_net;
	wire [0:0] tmpINTERRUPT_0__PinRight_net;
	electrical [0:0] tmpSIOVREF__PinRight_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PinRight
		 (.oe(tmpOE__PinRight_net),
		  .y({Net_178}),
		  .fb({tmpFB_0__PinRight_net[0:0]}),
		  .io({tmpIO_0__PinRight_net[0:0]}),
		  .siovref(tmpSIOVREF__PinRight_net),
		  .interrupt({tmpINTERRUPT_0__PinRight_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PinRight_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PinLeft_net;
	wire [0:0] tmpFB_0__PinLeft_net;
	wire [0:0] tmpIO_0__PinLeft_net;
	wire [0:0] tmpINTERRUPT_0__PinLeft_net;
	electrical [0:0] tmpSIOVREF__PinLeft_net;

	cy_psoc3_pins_v1_10
		#(.id("7e611396-4419-4b1b-b6f6-9b200978eff0"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PinLeft
		 (.oe(tmpOE__PinLeft_net),
		  .y({Net_179}),
		  .fb({tmpFB_0__PinLeft_net[0:0]}),
		  .io({tmpIO_0__PinLeft_net[0:0]}),
		  .siovref(tmpSIOVREF__PinLeft_net),
		  .interrupt({tmpINTERRUPT_0__PinLeft_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PinLeft_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PinStop_net;
	wire [0:0] tmpFB_0__PinStop_net;
	wire [0:0] tmpIO_0__PinStop_net;
	wire [0:0] tmpINTERRUPT_0__PinStop_net;
	electrical [0:0] tmpSIOVREF__PinStop_net;

	cy_psoc3_pins_v1_10
		#(.id("6c283a11-d2ff-4307-8d8e-f3ac799a082f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PinStop
		 (.oe(tmpOE__PinStop_net),
		  .y({Net_195}),
		  .fb({tmpFB_0__PinStop_net[0:0]}),
		  .io({tmpIO_0__PinStop_net[0:0]}),
		  .siovref(tmpSIOVREF__PinStop_net),
		  .interrupt({tmpINTERRUPT_0__PinStop_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PinStop_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_80 ControlStatusRegs (
        .clock(1'b0),
        .control_0(Net_178),
        .control_1(Net_179),
        .control_2(Net_195),
        .control_3(Net_193),
        .control_4(Net_192),
        .control_5(Net_191),
        .control_6(Net_185),
        .control_7(Net_188),
        .reset(1'b0));
    defparam ControlStatusRegs.Bit0Mode = 0;
    defparam ControlStatusRegs.Bit1Mode = 0;
    defparam ControlStatusRegs.Bit2Mode = 0;
    defparam ControlStatusRegs.Bit3Mode = 0;
    defparam ControlStatusRegs.Bit4Mode = 0;
    defparam ControlStatusRegs.Bit5Mode = 0;
    defparam ControlStatusRegs.Bit6Mode = 0;
    defparam ControlStatusRegs.Bit7Mode = 0;
    defparam ControlStatusRegs.BitValue = 0;
    defparam ControlStatusRegs.BusDisplay = 0;
    defparam ControlStatusRegs.ExtrReset = 0;
    defparam ControlStatusRegs.NumOutputs = 8;

    cy_annotation_universal_v1_0 WS2812LEDs_1 (
        .connect({
            Net_1,
            Net_3,
            Net_22
        })
    );
    defparam WS2812LEDs_1.comp_name = "WS2812String_v1_0";
    defparam WS2812LEDs_1.port_names = "Din, GND, V5";
    defparam WS2812LEDs_1.width = 3;

    StripLights_v3_0_1 StripLights (
        .rdy(Net_200),
        .S0(Net_199),
        .S1(Net_201),
        .S10(Net_202),
        .S11(Net_203),
        .S12(Net_204),
        .S13(Net_205),
        .S14(Net_206),
        .S15(Net_207),
        .S2(Net_208),
        .S3(Net_209),
        .S4(Net_210),
        .S5(Net_211),
        .S6(Net_212),
        .S7(Net_213),
        .S8(Net_214),
        .S9(Net_215));

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_3
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_22
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

	wire [0:0] tmpOE__S0_net;
	wire [0:0] tmpFB_0__S0_net;
	wire [0:0] tmpIO_0__S0_net;
	wire [0:0] tmpINTERRUPT_0__S0_net;
	electrical [0:0] tmpSIOVREF__S0_net;

	cy_psoc3_pins_v1_10
		#(.id("4665778c-0d4b-4b9b-b208-f876e26b079c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		S0
		 (.oe(tmpOE__S0_net),
		  .y({Net_199}),
		  .fb({tmpFB_0__S0_net[0:0]}),
		  .io({tmpIO_0__S0_net[0:0]}),
		  .siovref(tmpSIOVREF__S0_net),
		  .interrupt({tmpINTERRUPT_0__S0_net[0:0]}),
		  .annotation({Net_1}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__S0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

