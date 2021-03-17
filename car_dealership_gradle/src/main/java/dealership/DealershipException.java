package dealership;

public class DealershipException extends Exception {
    public DealershipException() {
    }

    public DealershipException(String message) {
        super(message);
    }

    public DealershipException(String message, Throwable cause) {
        super(message, cause);
    }

    public DealershipException(Throwable cause) {
        super(cause);
    }
}
