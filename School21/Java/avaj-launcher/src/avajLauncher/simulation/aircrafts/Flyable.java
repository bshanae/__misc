package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.weather.WeatherTower;

public interface    Flyable
{
    void            updateConditions();
    void            registerTower(WeatherTower weatherTower);
}