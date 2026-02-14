void withoutLoopLogic(int x, vector<int> &arr){
    if(x <= 0) return;

    withoutLoopLogic(x-1, arr);
    arr.push_back(x);
}

vector<int> printNos(int x) {
    // Write Your Code Here
    vector<int> arr;

    withoutLoopLogic(x, arr);
    return arr;
}
