#include "Person.hpp"

Form* Secretary::createForm(FormType p_formType) {
    switch (p_formType)
    {
    case FormType::CourseFinished:
        Form *ret = new CourseFinishedForm(FormType::CourseFinished);
        return ret;
        break;
    case FormType::NeedMoreClassRoom:
        Form *ret = new NeedMoreClassRoomForm(FormType::NeedMoreClassRoom);
        return ret;
        break;
    case FormType::NeedCourseCreation:
        Form *ret = new NeedCourseCreationForm(FormType::NeedCourseCreation);
        return ret;
        break;
    case FormType::SubscriptionToCourse:
        Form *ret = new SubscriptionToCourseForm(FormType::SubscriptionToCourse);
        return ret;
        break;
    default:
        return nullptr;
        break;
    }
}