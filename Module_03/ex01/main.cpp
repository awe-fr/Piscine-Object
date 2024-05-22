#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

void    get_price(std::vector<article> articles, std::string client, std::string date, int id) {
    ThuesdayDiscount    cmdThuesdayDiscount(&articles, client, date, id);
    PackageReductionDiscount    cmdPackageReductionDiscount(&articles, client, date, id);
    Command cmdCommand(&articles, client, date, id);

    cmdThuesdayDiscount.get_total_price();
    cmdPackageReductionDiscount.get_total_price();
    std::cout << "Total price of your order is : " << cmdCommand.get_total_price() << std::endl;
}

int main() {
    std::vector<article> articles;
    article a{"Pc", 2400, 2};
    article b{"Keyboard", 150, 3};
    article c{"Mouse", 50, 1};
    articles.push_back(a);
    articles.push_back(b);
    articles.push_back(c);
    get_price(articles, "Michel", "Jeudi", 1);
    get_price(articles, "Michel", "Vendredi", 2);

    std::vector<article> articles2;
    article d{"Apple", 2, 3};
    articles2.push_back(d);
    get_price(articles2, "Jean", "Samedi", 3);
    get_price(articles2, "Jean", "Jeudi", 4);
}