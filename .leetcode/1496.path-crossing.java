/*
 * @lc app=leetcode id=1496 lang=java
 *
 * [1496] Path Crossing
 */

// @lc code=start

import java.util.*;

class Point implements Comparable<Point>{
    int x, y;

    public static int HASH_CODE = 13039;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int hashCode() {
        return HASH_CODE;
    }

    @Override
    public boolean equals(Object o) {
        Point otherPoint = (Point) o;
        return compareTo(otherPoint) == 0;
    }

    @Override
    public int compareTo(Point o) {
        return (this.x - o.x) * 3 + (this.y - o.y) * 4;
    }

    public void move(Point direction) {
        this.x += direction.x;
        this.y += direction.y;
    }

    @Override
    public String toString() {
        return "(" + x + "," + y + ")";
    }

    public Point deepCopy() {
        return new Point(x, y);
    }
}
class Solution {
    public Point getDirection(char c) {
        switch (c) {
            case 'N':
                return new Point(0, 1);

            case 'E':
                return new Point(1, 0);

            case 'W':
                return new Point(-1, 0);

            case 'S':
                return new Point(0, -1);

            default:
                return new Point(-1, -1);
        }
    }

    public boolean isPathCrossing(String path) {
        Set<Point> pointsAppear = new HashSet<>();

        Point beginPoint = new Point(0, 0);
        pointsAppear.add(beginPoint.deepCopy());

        for (char direction : path.toCharArray()) {
            Point digitalDirection = getDirection(direction);
            beginPoint.move(digitalDirection);
            if (pointsAppear.contains(beginPoint)) {
                return true;
            } else {
                pointsAppear.add(beginPoint.deepCopy());
            }
        }

        return false;

    }
}
// @lc code=end

