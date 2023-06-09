import React from 'react'
import DiaryItem from './DiaryItem'

export default function DiaryList({ diaryList, onRemove, onEdit }) {
  return (
    <div>
      <h2>일기 리스트</h2>
      <h4>{diaryList.length}개의 일기가 있습니다.</h4>
      {diaryList.map(itr => (
        <DiaryItem onEdit={onEdit} onRemove={onRemove} id={itr.id} {...itr} />
      ))}
    </div>
  )
}

// 여기서 diaryList가 undefined인 경우를 대비해 디폴트 prop을 활용해 예외처리
DiaryList.defaultProps = {
  diaryList: [],
}
