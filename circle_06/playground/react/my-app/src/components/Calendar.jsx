import './calendar.css'

function Calendar(props)
{   
    const year = props.date.toLocaleString('en-US' , {month: 'long'});
    const month = props.date.toLocaleString('en-US', {day: '2-digit'});
    const days = props.date.getFullYear();

    return(
        <div className='expense-date'>
            <div className='expense-date__year'>{year}</div>
            <div className='expense-date__month'>{month}</div>
            <div className='expense-date__day'>{days}</div>
        </div>
    )
}

export default Calendar;