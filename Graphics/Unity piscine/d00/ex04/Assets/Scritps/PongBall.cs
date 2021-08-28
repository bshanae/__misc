using System;
using UnityEngine;
using Random = UnityEngine.Random;

public class PongBall : MonoBehaviour
{
    #region interface

    public Vector2 Min => transform.position.ToVector2() - new Vector2(radius, radius);
    public Vector2 Max => transform.position.ToVector2() + new Vector2(radius, radius);

    public void Reflect(Vector2 normal)
    {
        _velocity = Vector2Tools.Reflect(_velocity, normal);
    }

    public enum PushDirection
    {
        FromLeft,
        FromRight,
        FromTop,
        FromBottom
    }

    private const float PushEpsilon = 0.001f;

    public void Push(PushDirection direction, float limit)
    {
        switch (direction)
        {
            case PushDirection.FromLeft:
                transform.position = transform.position.SetX(limit + radius + PushEpsilon); 
                break;

            case PushDirection.FromRight:
                transform.position = transform.position.SetX(limit - radius - PushEpsilon);
                break;

            case PushDirection.FromTop:
                transform.position = transform.position.SetY(limit - radius - PushEpsilon);
                break;

            case PushDirection.FromBottom:
                transform.position = transform.position.SetY(limit + radius + PushEpsilon);
                break;

            default:
                throw new ArgumentOutOfRangeException(nameof(direction), direction, null);
        }
    }

    #endregion

    #region engine fields

    [SerializeField] private float xMin;
    [SerializeField] private float xMax;
    [SerializeField] private float yMin;
    [SerializeField] private float yMax;
    [SerializeField] private float radius;
    [SerializeField] private float speed;
    [SerializeField] private Player leftPlayer;
    [SerializeField] private Player rightPlayer;
    
    #endregion
    
    #region engine events

    private void Start()
    {
        ResetPositionAndVelocity();
    }

    private void Update()
    {
        if (transform.position.y - radius <= yMin)
        {
            _velocity = Vector2Tools.Reflect(_velocity, Vector2.up);
            Push(PushDirection.FromBottom, yMin);
        }

        if (transform.position.y + radius >= yMax)
        {
            _velocity = Vector2Tools.Reflect(_velocity, Vector2.down);
            Push(PushDirection.FromTop, yMax);
        }

        transform.Translate(_velocity * Time.deltaTime);

        if (transform.position.x - radius <= xMin)
        {
            rightPlayer.Score++;
            ResetPositionAndVelocity();
            PrintScore();
        }
        else if (transform.position.x + radius >= xMax)
        {
            leftPlayer.Score++;
            ResetPositionAndVelocity();
            PrintScore();
        }
    }
    
    #endregion

    #region main
    
    private Vector2 _velocity;

    private void ResetPositionAndVelocity()
    {
        transform.position = Vector2.zero;

        _velocity = new Vector2(Random.Range(0f, 1f), Random.Range(0f, 1f));
        _velocity = Vector2Tools.Normalize(_velocity);
        _velocity *= speed;
    }

    private void PrintScore()
    {
        Debug.Log($"Player 1: {leftPlayer.Score} | Player 2: {rightPlayer.Score}");
    }

    #endregion
}
