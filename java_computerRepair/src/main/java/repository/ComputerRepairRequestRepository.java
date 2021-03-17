package repository;

import model.ComputerRepairRequest;
import model.RequestStatus;

import java.util.List;

public interface ComputerRepairRequestRepository extends Repository<Integer,ComputerRepairRequest>{
    List<ComputerRepairRequest> findByOwnerName(String name);
    List<ComputerRepairRequest> findByModel(String model);
    List<ComputerRepairRequest> filterdByStatus(RequestStatus status);
    List<ComputerRepairRequest> filterByModelAndStatus(String model,RequestStatus status);

    List<ComputerRepairRequest> filterByDate(String dateValue);

}
