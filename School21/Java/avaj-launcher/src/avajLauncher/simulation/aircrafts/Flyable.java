package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.towers.WeatherTower;

public interface    Flyable
{
    void            updateConditions();
    void            registerTower(WeatherTower weatherTower);
}