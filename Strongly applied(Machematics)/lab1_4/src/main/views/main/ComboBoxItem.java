package main.views.main;

public class ComboBoxItem {
    private final String text;
    private final Object payload;

    public ComboBoxItem(String text, Object payload) {
        this.text = text;
        this.payload = payload;
    }

    public String getText() {
        return text;
    }

    public Object getPayload() {
        return payload;
    }

    @Override
    public String toString() {
        return text;
    }

}
