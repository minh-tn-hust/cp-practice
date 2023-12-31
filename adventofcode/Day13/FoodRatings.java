import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

class Food implements Comparable<Food> {
    public static int FOOD_HASH_CODE = 123132;
    String name;
    int rating;

    public Food(String food, int rating) {
        this.name = food;
        this.rating = rating;
    }

    @Override
    public int hashCode() {
        return FOOD_HASH_CODE;
    }

    @Override
    public boolean equals(Object o) {
        Food otherFood = (Food) o;
        return name.equals(otherFood.name) && rating == otherFood.rating;
    }

    @Override
    public int compareTo(Food o) {
        return rating * 100 + name.compareTo(o.name);
    }

    @Override
    public String toString() {
        return "(" + name + ", " + rating + ")";
    }
}

class FoodRatings {
    public Map<String, TreeSet<Food>> cuisineMap;
    public Map<String, String> foodToCuisine;
    public Map<String, Integer> foodToRating;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        initCuisineMap(cuisines);
        addFoodToCuisineMap(foods, cuisines, ratings);
        initFoodMappingCuisine(cuisines, foods);
        initFoodMappingRating(foods, ratings);
    }


    private void initCuisineMap(String[] cuisines) {
        cuisineMap = new HashMap<>();
        for (String cuisine : cuisines) {
            if (cuisineMap.get(cuisine) == null) {
                cuisineMap.put(cuisine, new TreeSet<Food>());
            }
        }
    }

    private void addFoodToCuisineMap(String[] foods, String[] cuisines, int[] ratings) {
        int size = cuisines.length;
        for (int i = 0; i < size; i++) {
            String food = foods[i];
            String cuisine = cuisines[i];
            int rating = ratings[i];
            Food newFood = new Food(food, rating);
            cuisineMap.get(cuisine).add(newFood);
        }
    }

    private void initFoodMappingCuisine(String[] cuisines, String[] foods) {
        foodToCuisine = new HashMap<String, String>();
        int size = foods.length;
        for (int i = 0; i < size; i++) {
            foodToCuisine.put(foods[i], cuisines[i]);
        }
    }

    private void initFoodMappingRating(String[] foods, int[] ratings) {
        foodToRating = new HashMap<String, Integer>();
        int size = foods.length;
        for (int i = 0; i < size; i++) {
            foodToRating.put(foods[i], ratings[i]);
        }
    }

    public void changeRating(String food, int newRating) {
        String cuisine = foodToCuisine.get(food);
        Integer rating = foodToRating.get(food);
        Food changedFood = new Food(food, rating);
        Set<Food> foods = cuisineMap.get(cuisine);

        foods.remove(changedFood);
        changedFood.rating = newRating;
        foods.add(changedFood);
    }
    
    public String highestRated(String cuisine) {
        Food a = new Food("kimchi", 9);
        Food b= new Food("bulgogi", 7);
        System.out.println(a.compareTo(b));
        return "";

    }
}