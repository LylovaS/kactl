/**
* Author: Sofia Lylova
 * Date: 2025-12-04
 * License: CC0
 * Source: folklore
 * Description: 2D segment tree for rectangle assignment and queries in points
 * Remove v = new Node(*v) to remove persistence
 * Time: O(\log{N} \cdot \log{M}) for query and update, O(N \cdot M) for push_down
 * Status: tested with task
 */
#pragma once

const pii unit = {-1, 1}; // pii -> {time, val}
struct Tree {
    vector<pii> s; int n, t = 0;
    Tree(int n) : s(2*n, unit), n(n) {}
    void update(int b, int e, pii val) { // assign [b, e) to val
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) s[b++] = val;
            if (e % 2) s[--e] = val;
        }
    }
    void update(int b, int e, int val) {
        update(b, e, {t++, val});
    }
    pii query(int x) {
        pii res = unit;
        for (x += n; x > 0; x /= 2)
            res = max(res, s[x]);
        return res;
    }
    void push_down() {
        for (int i = 1; i < n; ++i) {
            s[2 * i] = max(s[2 * i], s[i]);
            s[2 * i + 1] = max(s[2 * i + 1], s[i]);
        }
    }
};

struct Tree2 {
    vector<Tree> s; int n, t = 0;
    Tree2(int n, int m) : s(2*n, Tree{m}), n(n) {}
    void update(int x0, int x1, int y0, int y1, int val) { // assign [b, e) to val
        pii p = {t++, val};
        for (x0 += n, x1 += n; x0 < x1; x0 /= 2, x1 /= 2) {
            if (x0 % 2) s[x0++].update(y0, y1, p);
            if (x1 % 2) s[--x1].update(y0, y1, p);
        }
    }
    pii query(int x, int y) {
        pii res = unit;
        for (x += n; x > 0; x /= 2) {
            res = max(res, s[x].query(y));
        }
        return res;
    }
    void push_down() {
        for (int i = 1; i < n; ++i) {
            s[i].push_down();
            rep(j, 1, 2 * n) {
                s[2 * i].s[j] = max(s[2 * i].s[j], s[i].s[j]);
                s[2 * i + 1].s[j] = max(s[2 * i + 1].s[j], s[i].s[j]);
            }
        }
        rep(i, n, 2 * n) s[i].push_down();
    }
};