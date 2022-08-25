#ifndef CART_H
#define CART_H
class cart
{
public:
    cart(int _offer_id,int _amount,int _productId,int _sellerId,string _productName,float _price,string _discount_code="")
    {
        offerId = _offer_id;
        amount = _amount;
        productId = _productId;
        sellerId = _sellerId;
        productId = _productId;
        discount_code = _discount_code;
        price = _price;
    }
    float return_price(){return price;}
    int return_product_id(){return productId;}
    string return_product_name(){return productName;}
    int return_offer_id(){return offerId;} 
    int return_seller_id(){return sellerId;} 
    float return_totalPriceConsideringDiscount(){return  totalPriceConsideringDiscount;}
    int return_amount(){return amount;}


private:
int productId ;
string productName ;
int offerId ;
int sellerId ;
float totalPriceConsideringDiscount ;
int amount;
string discount_code;
float price;
};
#endif