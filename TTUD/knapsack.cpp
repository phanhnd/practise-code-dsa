#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// Cấu trúc biểu diễn một vật phẩm
// -------------------------------
struct Item {
    int id;          // chỉ số ban đầu
    double value;    // giá trị
    double weight;   // trọng lượng
    double ratio;    // value / weight
};

// -------------------------------
// Node biểu diễn trạng thái trong cây
// -------------------------------
struct Node {
    int level;       // vật đang xét (0-based)
    double profit;   // tổng giá trị hiện tại
    double weight;   // tổng trọng lượng hiện tại
    double bound;    // cận trên (upper bound)
    vector<int> path; // đường đi (các vật đã chọn hoặc bỏ)
};

// -------------------------------
// Hàm tính upper bound cho một node
// -------------------------------
double calcBound(const Node &node, double W, const vector<Item> &items) {
    if (node.weight >= W) return 0; // quá tải, không còn khả năng thêm

    double bound = node.profit;
    double totalWeight = node.weight;

    // duyệt các vật tiếp theo để tính cận trên
    for (int i = node.level; i < (int)items.size(); ++i) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            bound += items[i].value;
        } else {
            // lấy phần còn lại (phân số)
            double remain = W - totalWeight;
            bound += items[i].value * (remain / items[i].weight);
            break;
        }
    }
    return bound;
}

// -------------------------------
// Thuật toán Branch and Bound chính
// -------------------------------
pair<double, vector<int>> branchAndBoundKnapsack(vector<Item> items, double W) {
    int n = items.size();

    // Sắp xếp vật theo tỉ lệ value/weight giảm dần
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.ratio > b.ratio;
    });

    // Hàng đợi ưu tiên (ưu tiên node có bound cao hơn)
    struct Compare {
        bool operator()(const Node &a, const Node &b) const {
            return a.bound < b.bound;
        }
    };
    priority_queue<Node, vector<Node>, Compare> pq;

    // Node gốc (bắt đầu từ level 0)
    Node root;
    root.level = 0;
    root.profit = 0;
    root.weight = 0;
    root.path = vector<int>(n, 0);
    root.bound = calcBound(root, W, items);

    pq.push(root);

    double maxProfit = 0;
    vector<int> bestPath(n, 0);

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.bound <= maxProfit || curr.level >= n)
            continue; // không thể tốt hơn nghiệm hiện tại

        // --- Nhánh 1: chọn vật curr.level ---
        Node include = curr;
        include.level++;
        include.weight += items[curr.level].weight;
        include.profit += items[curr.level].value;
        include.path[curr.level] = 1;

        if (include.weight <= W && include.profit > maxProfit) {
            maxProfit = include.profit;
            bestPath = include.path;
        }

        include.bound = calcBound(include, W, items);
        if (include.bound > maxProfit)
            pq.push(include);

        // --- Nhánh 2: bỏ vật curr.level ---
        Node exclude = curr;
        exclude.level++;
        exclude.bound = calcBound(exclude, W, items);
        if (exclude.bound > maxProfit)
            pq.push(exclude);
    }

    return {maxProfit, bestPath};
}

// -------------------------------
// Hàm main (test)
// -------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double W;
    cout << "Nhap so luong vat (n) va suc chua cua tui (W): ";
    cin >> n >> W;

    vector<Item> items(n);
    cout << "Nhap gia tri (value) va trong luong (weight) cua tung vat:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
        items[i].id = i + 1;
        items[i].ratio = items[i].value / items[i].weight;
    }

    auto [maxProfit, bestPath] = branchAndBoundKnapsack(items, W);

    cout << "\n=== Ket qua ===\n";
    cout << "Tong gia tri toi da: " << maxProfit << "\n";
    cout << "Cac vat duoc chon:\n";
    for (int i = 0; i < n; ++i) {
        if (bestPath[i])
            cout << " - Vat " << items[i].id
                 << " (Gia tri: " << items[i].value
                 << ", Trong luong: " << items[i].weight << ")\n";
    }
}
