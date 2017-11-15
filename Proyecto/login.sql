CREATE PROCEDURE login  (IN nomina VARCHAR(10), IN contrasena VARCHAR(45))  
BEGIN
    SELECT ENTREGA.idENTREGA, ITEM.nombre, ITEM.cantidad FROM CLIENTE 
    natural join ENTREGA
    natural join ITEM
    where CLIENTE.RFCCliente = RFC
    group by ITEM.idITEM;
END