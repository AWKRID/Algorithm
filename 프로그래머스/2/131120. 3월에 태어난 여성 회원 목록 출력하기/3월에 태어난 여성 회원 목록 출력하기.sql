-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME,GENDER, DATE_FORMAT(DATE_OF_BIRTH,'%Y-%m-%d') as 생년월일 FROM MEMBER_PROFILE WHERE GENDER = 'W' AND DATE_OF_BIRTH LIKE '%-03-%' AND TLNO IS NOT NULL ORDER BY MEMBER_ID