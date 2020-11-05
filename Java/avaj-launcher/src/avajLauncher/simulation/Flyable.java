package avajLauncher.simulation;

import avajLauncher.simulation.WeatherTower;

public interface    Flyable
{
    void            updateConditions();
    void            registerTower(WeatherTower weatherTower);
}