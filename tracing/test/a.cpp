
const int NON_FIND = -1;
int binarySearch(vector<int> &arr, int value) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == value) {
            return middle;
        } else if (arr[middle] > value) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return NON_FIND;
}

vector<pair<int, int>> findPairSum(vector<int> arr, int x) {
    sort(arr.begin(), arr.end());

    vector<pair<int, int>> answer;

    for (int i = 0; i < arr.size(); i++) {
        int first = arr[i];
        int second = x - arr[i];
        if (binarySearch(arr, x - arr) != NON_FIND) {
            answer.push_back({first, second});
        }
    }

    return answer;
}