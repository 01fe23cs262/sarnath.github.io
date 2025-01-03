#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <queue>
#include <limits>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

// Customer queue management
class CustomerQueue {
    queue<string> customers;
public:
    void addCustomer(const string& name)
     {
        customers.push(name);
    }
    void removeCustomer() 
    {
        if (!customers.empty()) {
            cout << "Customer " << customers.front() << " has left.\n";
            customers.pop();
        } else 
        {
            cout << "No customers in the queue.\n";
        }
    }
    void displayQueue() 
    {
        if (customers.empty()) 
        {
            cout << "No customers in the queue.\n";
            return;
        }
        queue<string> temp = customers;
        cout << "Customers in the queue:\n";
        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

// Reservation system with number of seats
class Reservations 
{
    map<int, pair<string, int>> reservations;  // table number -> (customer name, number of seats)
    int totalTables;
public:
    Reservations(int tables) : totalTables(tables) {}
    bool reserveTable(int table, const string& name, int seats) 
    {
        if (table > totalTables || table < 1) 
            {
            cout << "Invalid table number.\n";
            return false;
        }
        if (reservations.count(table)) 
        {
            cout << "Table already reserved.\n";
            return false;
        }
        reservations[table] = make_pair(name, seats);
        cout << "Table " << table << " reserved for " << name << " with " << seats << " seats.\n";
        return true;
    }
    void releaseTable(int table) 
    {
        if (reservations.erase(table)) 
            {
            cout << "Table " << table << " is now available.\n";
        } 
        else 
        {
            cout << "Table " << table << " is not reserved.\n";
        }
    }
    void displayReservations() {
        if (reservations.empty()) 
            {
            cout << "No reservations.\n";
            return;
        }
        cout << "Current reservations:\n";
        for (auto &it : reservations) 
            {
            cout << "Table " << it.first << ": " << it.second.first << " (Seats: " << it.second.second << ")\n";
        }
    }
};

// Inventory management
class Inventory {
    map<string, int> items;
public:
    void updateItem(const string& item, int quantity)
     {
        items[item] += quantity;
        cout << "Updated " << item << " to " << items[item] << ".\n";
    }
    void checkInventory() {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "Current inventory:\n";
        for (auto &it : items) {
            cout << it.first << ": " << it.second << endl;
        }
    }
};

// Menu and billing system
class FoodMenu {
    map<string, double> menu;
    double totalRevenue = 0.0;
public:
    FoodMenu() {
        // Pre-populating the menu with 30 food items and their prices in rupees
        menu = {
            {"Pizza", 250.00},
            {"Burger", 120.00},
            {"Pasta", 180.00},
            {"Noodles", 150.00},
            {"French Fries", 80.00},
            {"Sandwich", 100.00},
            {"Soup", 90.00},
            {"Salad", 110.00},
            {"Ice Cream", 60.00},
            {"Pani Puri", 40.00},
            {"Dosa", 110.00},
            {"Samosa", 50.00},
            {"Vada Pav", 40.00},
            {"Biryani", 220.00},
            {"Fried Rice", 150.00},
            {"Spring Rolls", 100.00},
            {"Chole Bhature", 130.00},
            {"Pav Bhaji", 120.00},
            {"Aloo Tikki", 60.00},
            {"Chole Puri", 150.00},
            {"Kebabs", 200.00},
            {"Momos", 120.00},
            {"Rolls", 150.00},
            {"Paratha", 90.00},
            {"Chaat", 70.00},
            {"Pakora", 80.00},
            {"Shawarma", 180.00},
            {"Ching's Manchurian", 140.00},
            {"Chicken Wings", 250.00}
        };
    }

    void addItem(const string& dish, double price) {
        menu[dish] = price;
    }
    
    
    
    

    void displayMenu() {
        cout << "Food Menu:\n";
        for (auto &it : menu) {
            cout << setw(20) << left << it.first << "Rs. " << it.second << endl;
        }
    }
    
    

    void takeOrder() {
        string dish;
        int quantity;
        double bill = 0.0;
        cout << "Enter orders (type 'done' to finish):\n";
        while (true) {
            cout << "Dish: ";
            cin >> dish;
            if (dish == "done") break;
            if (menu.count(dish)) {
                cout << "Quantity: ";
                cin >> quantity;
                bill += menu[dish] * quantity;
            } else {
                cout << "Dish not found.\n";
            }
        }
        cout << "Total bill: Rs. " << bill << endl;
        totalRevenue += bill;
        int people;

        cout << "Split among how many people? ";

        cin >> people;
        if (people > 0) {
            cout << "Each person owes: Rs. " << bill / people << endl;
        } else {
            cout << "Invalid number of people.\n";
        }
    }

    void printRevenue() {
        cout << "Total revenue for the day: Rs. " << totalRevenue << endl;
    }

    void resetRevenue() {
        totalRevenue = 0.0;
        cout << "Revenue reset to 0.\n";
    }
};



// Delivery system
class DeliverySystem {
    map<int, vector<pair<int, double>>> graph;

public:
    void addEdge(int u, int v, double w) {
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // Assuming undirected graph
    }

    void shortestDistance(int source, int destination) {
        map<int, double> dist;
        for (auto &it : graph) {
            dist[it.first] = numeric_limits<double>::infinity();
        }
        dist[source] = 0.0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        
        pq.emplace(0.0, source);
        

        while (!pq.empty()) {
            double distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (distance > dist[node]) continue;

            for (auto &neighbor : graph[node]) {
                int nextNode = neighbor.first;
                double edgeWeight = neighbor.second;

                if (dist[node] + edgeWeight < dist[nextNode])
                {
                    dist[nextNode] = dist[node] + edgeWeight;
                
                    pq.emplace(dist[nextNode], nextNode);
                }
            }
        }

        if (dist[destination] != numeric_limits<double>::infinity()) 
        {
            cout << "Shortest distance from " << source << " to " << destination << " is " << dist[destination] << "\n";
        } else {
            cout << "No path found from " << source << " to " << destination << "\n";
        }
    }
};

// Lodging System
class LodgingSystem {
    set<pair<int, string>> rooms; // Room ID and Type (sorted by price)
    map<int, pair<string, double>> roomTypes; // Room Type -> Price

public:
    LodgingSystem() {
        roomTypes[1] = {"Single", 1000.00};
        roomTypes[2] = {"Double", 1500.00};
        roomTypes[3] = {"Suite", 2500.00};
        rooms.insert({1, "Single"});
        rooms.insert({2, "Double"});
        rooms.insert({3, "Suite"});
    }

    void displayAvailableRooms() {
        cout << "Available Rooms:\n";
        for (const auto &room : rooms) 
        {
            cout << "Room Type: " << room.second << ", Price: Rs. " << roomTypes[room.first].second << endl;
        }
    }

    void bookRoom(int roomType, int days) {
        auto it = rooms.lower_bound({roomType, ""});
        if (it != rooms.end()) 
        {
            double price = roomTypes[it->first].second * days;
            cout << "Room " << roomTypes[it->first].first << " booked for " << days << " days. Total Price: Rs. " << price << endl;
            rooms.erase(it);
        } else {
            cout << "No rooms of this type available.\n";
        }
    }

    void releaseRoom(int roomType) {
        rooms.insert({roomType, roomTypes[roomType].first});
        cout << "Room type " << roomTypes[roomType].first << " is now available.\n";
    }
};

// Main function
int main() {
    CustomerQueue queue;
    Reservations reservations(10);
    Inventory inventory;
    FoodMenu menu;
    DeliverySystem delivery;
    LodgingSystem lodging;

    // Corrected initialization of connections vector
    vector<tuple<int, int, double>> connections = {
        make_tuple(0, 1, 1.0),
        make_tuple(0, 2, 1.0),
        make_tuple(0, 3, 1.0),
        make_tuple(0, 4, 1.0),
        make_tuple(1, 5, 2.0),
        make_tuple(2, 6, 1.5),
        make_tuple(3, 7, 1.2)
    };

    // Adding edges to the delivery system
    for (auto &conn : connections) {
        int u = get<0>(conn);
        int v = get<1>(conn);
        double w = get<2>(conn);
        delivery.addEdge(u, v, w);
    }

    int choice;
    do {
        cout << "\nRestaurant Management System\n";
        cout << "1. Manage Customer Queue\n";
        cout << "2. Manage Reservations\n";
        cout << "3. Manage Inventory\n";
        cout << "4. Manage Menu and Billing\n";
        cout << "5. Delivery System\n";
        cout << "6. Lodging System\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int queueChoice;
                do {
                    cout << "\nCustomer Queue Management\n";
                    cout << "1. Add Customer\n";
                    cout << "2. Remove Customer\n";
                    cout << "3. Display Queue\n";
                    cout << "4. Back\n";
                    cout << "Enter your choice: ";
                    cin >> queueChoice;

                    if (queueChoice == 1) {
                        string name;
                        cout << "Enter customer name: ";
                        cin >> name;
                        queue.addCustomer(name);
                    } else if (queueChoice == 2) 
                    {
                        queue.removeCustomer();
                    } else if (queueChoice == 3)
                     {
                        queue.displayQueue();
                    }
                } 
                while (queueChoice != 4);
                break;
            }
            case 2: 
                {
                int reservationChoice;
                do {
                    cout << "\nReservation Management\n";
                    cout << "1. Reserve Table\n";
                    cout << "2. Release Table\n";
                    cout << "3. Display Reservations\n";
                    cout << "4. Back\n";
                    cout << "Enter your choice: ";
                    cin >> reservationChoice;

                    if (reservationChoice == 1) 
                        {
                        int table;
                        string name;
                        int seats;
                        cout << "Enter table number: ";
                        cin >> table;
                        cout << "Enter customer name: ";
                        cin >> name;
                        cout << "Enter number of seats: ";
                        cin >> seats;
                        reservations.reserveTable(table, name, seats);
                    } else if (reservationChoice == 2)
                     {
                        int table;
                        cout << "Enter table number to release: ";
                        cin >> table;
                        reservations.releaseTable(table);
                    } else if (reservationChoice == 3) 
                    {
                        reservations.displayReservations();
                    }
                } while (reservationChoice != 4);
                break;
            }
            case 3: {
                int inventoryChoice;
                do {
                    cout << "\nInventory Management\n";
                    cout << "1. Update Item\n";
                    cout << "2. Check Inventory\n";
                    cout << "3. Back\n";
                    cout << "Enter your choice: ";
                    cin >> inventoryChoice;

                    if (inventoryChoice == 1)
                        {
                        string item;
                        int quantity;
                        cout << "Enter item name: ";
                        cin >> item;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        inventory.updateItem(item, quantity);
                    } else if (inventoryChoice == 2) 
                    {
                        inventory.checkInventory();
                    }
                } while (inventoryChoice != 3);
                break;
            }
            case 4: {
                int menuChoice;
                do {
                    cout << "\nMenu and Billing\n";
                    cout << "1. Display Menu\n";
                    cout << "2. Take Order\n";
                    cout << "3. Display Total Revenue\n";
                    cout << "4. Reset Revenue\n";
                    cout << "5. Back\n";
                    cout << "Enter your choice: ";
                    cin >> menuChoice;

                    if (menuChoice == 1) {
                        menu.displayMenu();
                    } else if (menuChoice == 2) 
                    {
                        menu.takeOrder();
                    } else if (menuChoice == 3)
                     {
                        menu.printRevenue();
                    } else if (menuChoice == 4)
                     {
                        menu.resetRevenue();
                    }
                } while (menuChoice != 5);
                break;
            }
            case 5: {
                int deliveryChoice;
                do {
                    cout << "\nDelivery System\n";
                    cout << "1. Calculate Shortest Distance\n";
                    cout << "2. Back\n";
                    cout << "Enter your choice: ";
                    cin >> deliveryChoice;

                    if (deliveryChoice == 1) {
                        int source, destination;
                        cout << "Enter source location: ";
                        cin >> source;
                        cout << "Enter destination location: ";
                        cin >> destination;
                        delivery.shortestDistance(source, destination);
                    }
                } while (deliveryChoice != 2);
                break;
            }
            case 6: {
                int lodgingChoice;
                do {
                    cout << "\nLodging System\n";
                    cout << "1. Display Available Rooms\n";
                    cout << "2. Book Room\n";
                    cout << "3. Release Room\n";
                    cout << "4. Back\n";
                    cout << "Enter your choice: ";
                    cin >> lodgingChoice;

                    if (lodgingChoice == 1) {
                        lodging.displayAvailableRooms();
                    } else if (lodgingChoice == 2) {
                        int roomType, days;
                        cout << "Enter room type (1 for Single, 2 for Double, 3 for Suite): ";
                        cin >> roomType;
                        cout << "Enter number of days: ";
                        cin >> days;
                        lodging.bookRoom(roomType, days);
                    } else if (lodgingChoice == 3) {
                        int roomType;
                        cout << "Enter room type to release (1 for Single, 2 for Double, 3 for Suite): ";
                        cin >> roomType;
                        lodging.releaseRoom(roomType);
                    }
                } while (lodgingChoice != 4);
                break;
            }
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


