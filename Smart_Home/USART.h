#ifndef USART_H
#define USART_H

void USART_voidInit (void);

/*u8   USART_u8SendData (u8 Copy_u8Data);
 
u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData) ;

u8   USART_u8SendStringSynch (const u8 * Copy_pchString);
u8   USART_u8SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void)) ;

u8   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
u8   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;
*/

void USART_vidEnable(void);
void USART_vidDisable(void);
void USART_vidEnable_Receiver(void);
void USART_vidDisable_Receiver(void);
void USART_vidEnable_Transmitter(void);
void USART_vidDisable_Transmitter(void);
void USART_vidEnable_RX_Int(void);
void USART_vidDisable_RX_Int(void);
void USART_vidEnable_TX_Int(void);
void USART_vidDisable_TX_Int(void);
void USART_vidEnable_UDR_Int(void);
void USART_vidDisable_UDR_Int(void);
void USART_vidSetCallBack_Rx(pf pfCallFuncRxCpy);
void USART_vidSetCallBack_Tx(pf pfCallFuncTxCpy);
void USART_vidSetCallBack_UDR(pf pfCallFuncUDRCpy);
void USART_Transmit(uint8 data);
void USART_TransmitString(uint8* data);
uint8 USART_Receive(void); 
#endif
