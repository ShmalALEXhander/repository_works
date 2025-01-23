import java.util.Arrays;
class Item implements Comparable<Item> {
    private int value;
    private int weight;

    public Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }

    public int getValue() {
        return value;
    }

    public int getWeight() {
        return weight;
    }

    public double getValuePerWeight() {
        return (double) value / weight;
    }

    @Override
    public int compareTo(Item other) {
        return Double.compare(other.getValuePerWeight(), this.getValuePerWeight());
    }
}
public class ContinuousKnapsack {
    public static double getMaxValue(int[] values, int[] weights, int capacity) {
        Item[] items = new Item[values.length];
        for (int i = 0; i < values.length; i++) {
            items[i] = new Item(values[i], weights[i]);
        }

        Arrays.sort(items);

        double totalValue = 0;
        int remainingCapacity = capacity;
        for (Item item : items) {
            if (remainingCapacity <= 0) {
                break;
            }

            int weight = Math.min(item.getWeight(), remainingCapacity);
            totalValue += weight * item.getValuePerWeight();
            remainingCapacity -= weight;
        }

        return totalValue;
    }

    public static void main(String[] args) {
        int[] values = {60, 100, 130};
        int[] weights = {10, 20, 30};
        int capacity = 50;

        double maxValue = getMaxValue(values, weights, capacity);
        System.out.println("Максимальная стоимость: " + maxValue);
    }
}