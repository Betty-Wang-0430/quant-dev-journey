#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

enum class Side {
    Buy,
    Sell
};

struct Order {
    int id;
    double price;
    int quantity;
    Side side;
};

class OrderBook {
private:
    std::unordered_map<int, Order> orders_by_id;
    std::map<double, std::vector<int>> bids;
    std::map<double, std::vector<int>> asks;

public:
    void add_order(const Order& order) {
        orders_by_id.emplace(order.id, order);
        if (order.side == Side::Buy) {
            bids[order.price].push_back(order.id);
        } else {
            asks[order.price].push_back(order.id);
        }
        
    }

    void add_sell_order(const Order& order) {
        orders_by_id.emplace(order.id, order);
        asks[order.price].push_back(order.id);
    }

    // const here means promise not to modify OrderBook
    double highest_bid() const {
        return bids.rbegin()->first;
    }

    double lowest_ask() const {
        return asks.begin()->first;
    }

    bool can_match() const {
        if (bids.empty() || asks.empty()) {
            return false;
        } else {
            return highest_bid() >= lowest_ask();
        }
    }

    void print_highest_bid() const {
        auto it = bids.rbegin();

        std::cout << "Highest price: " << it->first << "\n";

        for (const auto& order_id : it->second) {
        std::cout << "Order ID: " << order_id << "\n";
        }
    }

    int trade_quantity(int buy_quantity, int sell_quantity) const {
        return std::min(buy_quantity, sell_quantity);
    }

    int best_bid_id() const {
        return bids.rbegin()->second.front();
    }

    int best_ask_id() const {
        return asks.begin()->second.front();
    }

    void remove_from_price_level(std::vector<int>& order_ids, int order_id) {
        auto it = std::find(order_ids.begin(), order_ids.end(), order_id);
        if (it != order_ids.end()) {
            order_ids.erase(it);
        }
    }  
    
    void remove_order(int order_id) {
        auto& order = orders_by_id.at(order_id);
        double price = order.price;
        if (order.side == Side::Buy) {
            remove_from_price_level(bids[price], order_id);
            if (bids[price].empty()) {
                bids.erase(price);
            }
        } else {
            remove_from_price_level(asks[price], order_id);
            if (asks[price].empty()) {
                asks.erase(price);
            }
        }
        orders_by_id.erase(order_id); 
    }


    void execute_trade() {
        if (!can_match()) {
            return;
        }

        int buy_id = best_bid_id();
        int sell_id = best_ask_id();

        // Get quantities before potentially removing orders
        int buy_quantity = orders_by_id.at(buy_id).quantity;
        int sell_quantity = orders_by_id.at(sell_id).quantity;

        int quantity = trade_quantity(buy_quantity, sell_quantity);

        double trade_price = orders_by_id.at(sell_id).price;

        std::cout << "Trade: " << quantity
                  << " units @ " << trade_price << "\n"
                  << "Buyer: " << buy_id << "\n"
                  << "Seller: " << sell_id << "\n\n";

        // Update quantities
        orders_by_id.at(buy_id).quantity -= quantity;
        orders_by_id.at(sell_id).quantity -= quantity;

        // Remove fully filled orders
        if (orders_by_id.at(buy_id).quantity == 0) {
            remove_order(buy_id);
        }

        if (orders_by_id.at(sell_id).quantity == 0) {
            remove_order(sell_id);
        }
    }

    void print_book() const {
        std::cout << "\n--- BIDS ---\n";

        for (auto it = bids.rbegin(); it != bids.rend(); ++it) {
            std::cout << it->first << ": ";

            for (int order_id : it->second) {
                std::cout << order_id << " ";
            }

            std::cout << "\n";
        }

        std::cout << "\n--- ASKS ---\n";

        for (const auto& [price, order_ids] : asks) {
            std::cout << price << ": ";

            for (int order_id : order_ids) {
                std::cout << order_id << " ";
            }

            std::cout << "\n";
        }
    }
     
};

int main() {

    /*
    Order order;
    order.id = 1;
    order.price = 100.5;
    order.quantity = 50;
    std::cout << "Order ID: " << order.id << "\n"
              << "Price: " << order.price << "\n"
              << "Quantity: " << order.quantity << "\n";

    */

    /*
    std::vector<Order> orders;
    // orders.push_back(Order{1,2,3})
    orders.emplace_back(1, 100.5, 50);
    orders.emplace_back(2, 101.0, 20);
    orders.emplace_back(3, 99.5, 100);
    for (const Order& o : orders) {
        std::cout << "Order ID: " << o.id << "\n"
                  << "Price: " << o.price << "\n"
                  << "Quantity: " << o.quantity << "\n\n";
    }
    */

    /*
    orders_by_id.emplace(1, Order{1, 100.5, 50});
    orders_by_id.emplace(2, Order{2, 101.0, 20});
    orders_by_id.emplace(3, Order{3, 99.5, 100});
    orders_by_id.emplace(4, Order{4, 101.0, 30});
    */

    /*
    auto it = orders_by_id.find(3);
    if (it != orders_by_id.end()) {
        std::cout << "Order ID: " << it->second.id << "\n"
                  << "Price: " << it->second.price << "\n"
                  << "Quantity: " << it->second.quantity << "\n\n";
    }
    */

    /*
    bids[100.5].push_back(1);
    bids[101.0].push_back(2);
    bids[99.5].push_back(3);
    bids[101.0].push_back(4);
    */

    /*
    for (const auto& b : bids) { 
        for (const auto& order_id : b.second) {
            std::cout << "Price: " << b.first << " "
                      << "Orders: " << order_id << "\n";
        }
    }
    */

    /*
    // rbegin gives the reverse iterator 
    auto it1 = std::rbegin(bids);
    if (it1 != bids.rend()) {
        std::cout << "Highest price: " << it1->first << "\n";
        for (const auto& order : it1->second) {
            std::cout << "Order ID: " << order << "\n";
        }
    }
    */

    OrderBook book;

    // Add buy orders
    book.add_order(Order{1, 100.5, 50, Side::Buy});
    book.add_order(Order{2, 101.0, 20, Side::Buy});
    book.add_order(Order{4, 101.0, 30, Side::Buy});

    // Add sell orders
    book.add_order(Order{3, 101.0, 40, Side::Sell});
    book.add_order(Order{5, 102.0, 50, Side::Sell});

    book.print_book();

    std::cout << "\nHighest bid: "
              << book.highest_bid() << "\n";

    std::cout << "Lowest ask: "
              << book.lowest_ask() << "\n";

    std::cout << "\nExecuting trades...\n";

    while (book.can_match()) {
        book.execute_trade();
    }

    book.print_book();

    return 0;
}