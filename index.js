
let i  = 0;
let cost = [20 , 40 , 50] ;
let arr = [] ;
let totalitems = 0 ;
let totalcost = 0 ;
let product = "A" ;
while( i < 3 ) {
    let quantity = prompt(`Please enter the quantity of product ${product}:`);
    arr.push({p:product , q : quantity}) ;
    product = String.fromCharCode(product.charCodeAt(0) + 1) 
    totalitems += quantity ; 
    totalcost += ( quantity * cost[ i ] ) ;
    i++;
}

let discount1 = 0 ;
let discount2 = 0 ;
let discount3 = 0 ;
let discount4 = 0 ;
let discount1name = "flat_10_discount" ;
let discount2name = "bulk_5_discount" ;
let discount3name = "bulk_10_discount" ;
let discount4name = "tiered_50_discount" ;

if( totalcost > 200 ) {
    discount1 = 10 ;
}
i = 0 ;
while( i < 3 ) {
    if( arr[ i ].q > 10 && discount2 != 0 ){
        discount2 = totalcost * 0.05 ;
    }
    if( arr[ i ].q > 20 && discount3 == 0  ){
        discount3 = totalcost * 0.1 ;
    }
    if( totalitems > 30 && arr[ i ].q > 15 ) {
        discount4 += ( 0.5 *  ((arr[ i ].q) - 15 ) ) ;
    }
    i++;
}
let finaldiscountname = "" ;
let maximum = Math.max( discount1 , discount2 , discount3 , discount4 ) ;
if(maximum == discount1 ) {
finaldiscountname = discount1name ;
}
if(maximum == discount2 ) {
    finaldiscountname = discount2name ;
}
if(maximum == discount3 ) {
    finaldiscountname = discount3name ;
}
if(maximum == discount4 ) {
    finaldiscountname = discount4name ;
}
if( maximum == 0 ) {
    finaldiscountname = "No Discount Applicable"
}
let ques = prompt("Do you want to wrap this product ? (Y/N) :") ;
let gift = 0;
if( ques == "Y" ) {
    totalcost++;
    gift++;
}
let shipping = (totalitems / 10 ) *  5 ;
i = 0 ;
while( i < 3 ) {
console.log(`${arr[ i ].p}  ${arr[ i ].q}  ${arr[ i ].q * cost[ i ]} `) ;
i++;
}
console.log(`Total Cost :${totalcost}`);
console.log(`Final Discount :${finaldiscountname} ${maximum}`) ;
console.log(`Shipping :${shipping} Gift Wrap Fee : ${gift} `  );
console.log(`Total Amount: ${( totalcost - maximum + shipping )}` ) ;